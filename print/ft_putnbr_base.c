/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:03:52 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/14 14:38:33 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	size_t		totalen;
	static int	count;

	count = 0;
	totalen = ft_strlen(base);
	if (nb >= totalen)
	{
		ft_putnbr_base(nb / (int)totalen, base);
	}
	count += ft_putchar(base[nb % (int)totalen]);
	return (count);
}

// int main(void)
// {
// 	ft_putnbr_base("1111112121212121212121212121212121212121",
			// "0123456789abcdef");
// 	printf("\n");
// 	printf("%p", "1111112121212121212121212121212121212121");
// 	return (0);
// }