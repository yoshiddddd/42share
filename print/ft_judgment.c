/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/16 00:02:15 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char ident, va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	if (ident == 'c')
		count = ft_charconver(va_arg(args, int), flag, ident);
	else if (ident == 's')
		count = ft_strconver(va_arg(args, char *));
	else if (ident == 'd' || ident == 'i')
		count = ft_putnbr_fd(va_arg(args, int));
	else if (ident == 'p')
		count = ft_pointconver((unsigned long long)va_arg(args, void *));
	else if (ident == 'u')
		count = ft_unsconver(va_arg(args, unsigned int));
	else if (ident == 'x' || ident == 'X')
		count = ft_hexconver(va_arg(args, unsigned int), ident);
	else if (ident == '%')
		count = ft_putchar(ident);
	return (count);
}

char	*ft_flag_check(const char *format, va_list args, t_flag *flag)
{
	int	i;

	i = 0;
	while (format[i+1] != '\0')
	{
		if (format[i+1] == '-')
			flag->minus = 1;
		else if (format[i+1] == ' ')
			flag->space = 1;
		else if (format[i+1] == '#')
			flag->sharp = 1;
		else if (format[i+1] == '+')
			flag->plus = 1;
		else if (format[i+1] == '0')
			flag->zero = 1;
		else
			break ;
		i++;
	}
	return ((char *)&format[i]);
}

char	*ft_field_check(char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;
	int		ansnum;

	i = 0;
	if(format[i+1] == '*')
	{
		flag->star_field = 1;
		flag->star_field_value = va_arg(args, int);
		return ((char *)&format[i+1]);
	}
	while ('0' <= format[i+1] && format[i+1] <= '9')
		i++;
	chnum = ft_substr(format, 0, i);
	flag->field = ft_atoi(chnum);

	free(chnum);
	return ((char *)&format[i]);
}

char	*ft_precision_check(char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;
	int		ansnum;

	i = 0;
	if (format[i+1] == '.')
	{
			if(format[i+2] == '*')
			{
				flag->star_precision = 1;
				flag->star_precision_value = va_arg(args, int);
				return ((char *)&format[i+2]);
			}
		while ('0' <= format[i+2] && format[i+2] <= '9')
			i++;
		chnum = ft_substr(format, 2, i);
		flag->precision = ft_atoi(chnum);
		free(chnum);
	}
	return ((char *)&format[i]);
}

int	ft_judgment(va_list args, const char *format)
{
	int		i;
	int		count;
	t_flag	*flag;
	t_flag	flag_init;

	flag_init = ft_flag_init();
	flag = &flag_init;
	i = 0;
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format = ft_flag_check(format, args, flag);
			format = ft_field_check(format, args, flag);
			format = ft_precision_check(format, args, flag);
			count += ft_check(*format+1, args, flag);
			i++;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}
