/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/14 21:25:44 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_(char ident, va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	if (ident == 'c')
		count = ft_charconver(va_arg(args, int), flag);
	else if (ident == 's')
		count = ft_putstr(va_arg(args, char *));
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
	while (format[i] != '\0')
	{
		if (format[i] == '-')
			flag->minus = 1;
		else if (format[i] == ' ')
			flag->space = 1;
		else if (format[i] == '#')
			flag->sharp = 1;
		else if (format[i] == '+')
			flag->plus = 1;
		else if (format[i] == '0')
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
	while ('0' <= format[i] && format[i] <= '9')
		i++;
	chnum = ft_substr(format, 0, i);
	flag->field = ft_atoi(chnum);

	return ((char *)&format[i]);
}

char	*ft_precision_check(char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;
	int		ansnum;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		while ('0' <= format[i] && format[i] <= '9')
			i++;
		chnum = ft_substr(format, 1, i);
		flag->precision = ft_atoi(chnum);
	}
	return ((char *)&format[i]);
}

int	ft_judgment(va_list args, const char *format)
{
	int		i;
	int		count;
	t_flag	ini_flag;
	t_flag	*flag;

	flag = &ini_flag;
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format = ft_flag_check(format, args, flag);
			format = ft_field_check(format, args, flag);
			format = ft_precision_check(format, args, flag);
			count += ft_check(format[i + 1], args, flag);
			i++;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	return (count);
}
