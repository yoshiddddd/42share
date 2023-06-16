/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:57:22 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/15 10:01:20 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_flag_init(void)
{
    t_flag flag;
    flag.minus = 0;
    flag.zero = 0;
    flag.field = 0;
    flag.precision = 0;
    flag.star_field = 0;
    flag.star_field_value = 0;
    flag.star_precision = 0;
    flag.star_precision_value = 0;
    flag.space = 0;
    flag.sharp = 0;
    flag.plus = 0;
    return (flag);
}