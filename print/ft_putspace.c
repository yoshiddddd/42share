/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:06:17 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/18 17:25:06 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putspace(int len)
{
	int count;

	count = 0;
	while (len> 0)
	{
		count += ft_putchar(' ');
		len--;
	}

	return (count);
}
