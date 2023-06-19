/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:46:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 20:02:08 by kyoshida         ###   ########.fr       */
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
	if (s == NULL)
		s = "(null)";
	string_len = ft_strlen(s);
	if (flag->precision > string_len)
		flag->precision = string_len;
	if (flag->minus == 1)
	{
		count += ft_putstr(s, flag->precision);
		count += ft_putspace(flag->width - count);
	}
	else
	{
		if (flag->precision == -1)
			flag->precision = string_len;
		count += ft_putspace(flag->width - flag->precision);
		count += ft_putstr(s, flag->precision);
	}
	return (count);
}

int	ft_int_write(int nbr, t_flag *flag)
{
	int	*count;
	int	zerocount;

	zerocount = 0;
	count = (int *)malloc(sizeof(int));
	*count = 0;
	if (flag->minus == 1)
	{
		*count += put_sign(flag, nbr);
		*count += put_zeros((flag->precision - ft_intlen(nbr)));
		ft_putnbr_fd(nbr, flag, count);
		*count += ft_putspace(flag->width - *count);
		// printf("   >>>%d\n",*count);
	}
	else
	{
		if (flag->zero == 0 || (flag->zero == 1 && flag->precision > 0)
			|| (flag->zero == 0 && flag->precision == 0))
		{
			zerocount = flag->precision - ft_intlen(nbr);
			if (zerocount < 0)
				zerocount = 0;
			*count += ft_putspace(flag->width - zerocount - ft_intlen(nbr)
					- check_sign(nbr, flag));
			*count += put_sign(flag, nbr);
			*count += put_zeros((flag->precision - ft_intlen(nbr)));
		}
		else
		{
			*count += put_sign(flag, nbr);
			*count += put_zeros((flag->precision - ft_intlen(nbr)
						- check_sign(nbr, flag)));
		}
		ft_putnbr_fd(nbr, flag, count);
	}
	zerocount = *count;
	free(count);
	return (zerocount);
}

int	ft_ptr_write(unsigned long long p, t_flag *flag)
{
	int	*count;
	int	*space_num;

	count = (int *)malloc(sizeof(int));
	*count = 0;
	space_num = (int *)malloc(sizeof(int));
	*space_num = 1;
	getnbr_base(p, "0123456789abcdef", space_num, flag);
	if (flag->minus == 0)
		*count += ft_putspace(flag->width - *space_num - 2);
	*count += ft_putstr("0x", 2);
	ft_putnbr_base(p, "0123456789abcdef", count, flag);
	if (flag->minus == 1)
		*count += ft_putspace(flag->width - *space_num - 2);
	free(space_num);
	return (*count);
}

int	ft_hex_write(unsigned int i, char ident, t_flag *flag)
{
	char	*hex;
	int		*count;
	if(flag)
	;
	i = 0;
	count = (int *)malloc(sizeof(int));
	count = 0;
	if (ident == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	// ft_putnbr_base((unsigned long long)i, hex, count);
	return (0);
}

int	ft_unsconver(unsigned int i)
{
	int	*count;

	i = 0;
	count = (int *)malloc(sizeof(int));
	count = 0;
	// ft_putnbr_base((unsigned long long)i, "0123456789", count);
	return (0);
}
