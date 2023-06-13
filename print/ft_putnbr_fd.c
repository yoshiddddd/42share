	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/12 21:51:44 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n)
{
	long	i;
	static int		count = 0;

	i = (long)n;
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10);
		ft_putnbr_fd(i % 10);
	}
	else
	{
		count += ft_putchar(i + '0');
	}
	return count;
}

// int main(void)
// {[]

// }
