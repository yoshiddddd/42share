/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 01:23:34 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n,t_flag *flag)
{
	long		i;
	static int	count = 0;
	i = (long)n;
	if(i == 0 && flag->precision >= 0)
	return 0;
	if (i < 0)
		i *= -1;
	if (i > 9)
	{
		ft_putnbr_fd(i / 10,flag);
		ft_putnbr_fd(i % 10,flag);
	}
	else
	{
		count += ft_putchar(i + '0');
	}
	return (count);
}

// int main(void)
// {[]

// }
