/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:46:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 12:36:38 by yoshidakazu      ###   ########.fr       */
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
		count += ft_putspace(flag->width - 1);
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
		if (flag->precision > string_len )
			flag->precision = string_len;

	if (flag->minus == 1)
	{
		count += ft_putstr(s, flag->precision);
		count += ft_putspace(flag->width - count);
	}
	else
	{
			if(flag->precision == 0)
				flag->precision = string_len;
		count += ft_putspace(flag->width - flag->precision);
		count += ft_putstr(s, flag->precision);
	}
	return (count);
}

int ft_int_write(int nbr,t_flag *flag)
{
	int count;
	int zerocount;

	zerocount = 0;
	count = 0;
	if(flag->minus == 1)
	{
		count +=put_sign(flag,nbr);
		
		count +=put_zeros(flag,(flag->precision - ft_intlen(nbr,flag)));
		count +=ft_putnbr_fd(nbr,flag);
		count +=ft_putspace(flag->width - count);
	}
	else
	{
		if(flag->zero==0 || (flag->zero==1&&flag->precision>0) ||(flag->zero==0&&flag->precision==0))
		{
			zerocount = flag->precision - ft_intlen(nbr,flag);
			if(zerocount<0)
				zerocount = 0;
			count +=ft_putspace(flag->width - zerocount - ft_intlen(nbr,flag)-check_sign(nbr,flag));
			count +=put_sign(flag,nbr);
			count +=put_zeros(flag,(flag->precision - ft_intlen(nbr,flag)));
		}
		else
		{
			count +=put_sign(flag,nbr);
			count +=put_zeros(flag,(flag->precision - ft_intlen(nbr,flag)-check_sign(nbr,flag)));
		}
			count +=ft_putnbr_fd(nbr,flag);
	}
	return count;
}

int	ft_ptr_write(unsigned long long p,t_flag *flag)
{
	int	count;
	int space_num;
	
	count = 0;
	space_num = 0;
	space_num = getnbr_base(p,"0123456789abcdef");
	if(flag->minus == 0)
		count +=ft_putspace(flag->width - space_num-2);
	count += ft_putstr("0x", 2);
	count += ft_putnbr_base(p, "0123456789abcdef");
	if(flag->minus == 1)
		count +=ft_putspace(flag->width - space_num - 2);
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
