/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:03:52 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 19:51:46 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nb, char *base, int *count,
		t_flag *flag)
{
	size_t	totalen;

	totalen = ft_strlen(base);
	if (nb == 0 && flag->precision >= 0)
		return ;
	if (nb >= totalen)
	{
		ft_putnbr_base(nb / (int)totalen, base, count, flag);
	}
	*count += ft_putchar(base[nb % (int)totalen]);
}

void	getnbr_base(unsigned long long nb, char *base, int *num, t_flag *flag)
{
	size_t	totalen;

	if (nb == 0 && flag->precision >= 0)
		(*num)--;
	totalen = ft_strlen(base);
	if (nb >= totalen)
	{
		(*num)++;
		getnbr_base(nb / (int)totalen, base, num, flag);
	}
}
