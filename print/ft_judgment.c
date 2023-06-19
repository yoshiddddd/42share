/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 19:59:41 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char ident, va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	if (ident == 'c')
		count = ft_char_write(va_arg(args, int), flag);
	else if (ident == 's')
		count = ft_str_write(va_arg(args, char *), flag);
	else if (ident == 'd' || ident == 'i')
		count = ft_int_write(va_arg(args, int), flag);
	else if (ident == 'p')
		count = ft_ptr_write((unsigned long long)va_arg(args, void *),flag);
	else if (ident == 'u')
		count = ft_unsconver(va_arg(args, unsigned int));
	else if (ident == 'x' || ident == 'X')
		count = ft_hex_write(va_arg(args, unsigned int), ident,flag);
	else if (ident == '%')
		count = ft_putchar(ident);
	return (count);
}

char	*ft_flag_check(const char *format, t_flag *flag)
{
	int	i;

	i = 0;

	while (format[i + 1] != '\0')
	{
		if (format[i + 1] == '-')
		{
			flag->minus = 1;
		}
		else if (format[i + 1] == ' ')
			flag->space = 1;
		else if (format[i + 1] == '#')
			flag->sharp = 1;
		else if (format[i + 1] == '+')
			flag->plus = 1;
		else if (format[i + 1] == '0')
			flag->zero = 1;
		else
			break ;
		i++;
	}
	return ((char *)&format[i+1]);
}

char	*ft_width_check(const char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;

	i = 0;
	if (format[i ] == '*')
	{
		flag->star_width = 1;
		flag->width = va_arg(args, int);
		return ((char *)&format[i+1]);
	}
	while ('0' <= format[i ] && format[i ] <= '9')
		i++;
	chnum = ft_substr(format, 0, i);
	flag->width = ft_atoi(chnum);
	free(chnum);
	chnum =NULL;
	return ((char *)&format[i]);
}

char	*ft_precision_check(const char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;

	i = 0;
	if (format[i ] == '.')
	{
		
			// printf("%d",flag->precision);
		if (format[i + 1] == '*')
		{
			flag->precision = va_arg(args, int);
			if(flag->precision < 0)
				flag->precision = 0;
			return ((char *)&format[i + 1]);
		}
		while ('0' <= format[i + 1] && format[i +1] <= '9')
			i++;
		chnum = ft_substr(format, 1, i);
		flag->precision = ft_atoi(chnum);
		free(chnum);
		chnum = NULL;
		i++;
	}
	return ((char *)&format[i]);
}

int	ft_judgment(va_list args, const char *format)
{
	int		i;
	int		count;
	t_flag	*flag;
	t_flag	flag_init;

	i = 0;
	count = 0;
	while (*format != '\0')
	{
	flag_init = ft_flag_init();
	flag = &flag_init;
		if (*format == '%')
		{
			format = ft_flag_check(format, flag);
			format = ft_width_check(format, args, flag);
			format = ft_precision_check(format, args, flag);
			count += ft_check(*format, args, flag);
			// printf("%s",va_arg(args, char *));
			// format++;
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}
