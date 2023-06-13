/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:46:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/13 19:27:47 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pointconver(unsigned long long  p)
{
	int count;
	
	count += ft_putstr("0x");
	count += ft_putnbr_base(p,"0123456789abcdef");
	return count-1;

}

int ft_hexconver(unsigned int i, char ident)
{
	char *hex;
	int n;
	if(ident == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	n = ft_putnbr_base((unsigned long long)i,hex);
	return n;
	
}

int 	ft_unsconver(unsigned int i)
{
	int n;
	n = ft_putnbr_base((unsigned long long)i,"0123456789");
	return n;
}