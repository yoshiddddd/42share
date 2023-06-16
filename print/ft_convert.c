/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:46:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/16 19:35:07 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_write(int args, t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->minus == 1)
	{
		count += ft_putchar((char)args);
		count += ft_putspace(flag->width - 1);
	}
	else
	{
		count += ft_putspace(flag);
		count += ft_putchar((char)args);
	}
	return (count - 1);
}

int	ft_str_write(char *s, t_flag *flag)
{
	int	count;
	int	string_len;

	string_len = 0;
	count = 0;
	string_len = ft_strlen(s);
	if (flag->minus == 1)
	{
		count += ft_putstr(s, flag->precision);
		count += ft_putspace(flag->width - count);
	}
	else
	{
		if (flag->precision > string_len || flag->precision == 0)
			flag->precision = string_len;
		count += ft_putspace(flag->width - flag->precision);
		count += ft_putstr(s, flag->precision);
	}
	return (count - 1);
}

int ft_int_write(int nbr,t_flag *flag)
{
	int count;

	count = 0;

		
}

int	ft_pointconver(unsigned long long p)
{
	int	count;

	count = 0;
	count += ft_putstr("0x", 2);
	count += ft_putnbr_base(p, "0123456789abcdef");
	return (count - 1);
}

int	ft_hexconver(unsigned int i, char ident)
{
	char	*hex;
	int		n;

	if (ident == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	n = ft_putnbr_base((unsigned long long)i, hex);
	return (n);
}

int	ft_unsconver(unsigned int i)
{
	int	n;

	n = ft_putnbr_base((unsigned long long)i, "0123456789");
	return (n);
}
