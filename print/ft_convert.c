/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:46:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/15 13:36:14 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_charconver(va_list args, t_flag *flag,char c)
{
	int	count;

	count = 0;
	ft_get_flag(flag,args,c);
	count += ft_putchar(c);
	return (count - 1);
}

int	ft_pointconver(unsigned long long p)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
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

int ft_strconver(char *s)
{
	int	count;

	count = 0;
	count += ft_putstr(s);
	return (count - 1);
}
