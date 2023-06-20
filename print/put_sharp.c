/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:33:12 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/20 11:33:56 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_sharp(t_flag *flag)
{
    int count;

    count = 0;
    if (flag->sharp == 1)
    {
        count += ft_putchar('0');
        count += ft_putchar('x');
    }
    return (count);
}