/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:57:22 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/16 12:00:55 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_flag_init(void)
{
    t_flag flag;
    flag.minus = 0;
    flag.zero = 0;
    flag.width = 0;
    flag.precision = 0;
    flag.star_width = 0;
    flag.star_width_value = 0;
    flag.star_precision = 0;
    flag.star_precision_value = 0;
    flag.space = 0;
    flag.sharp = 0;
    flag.plus = 0;
    return (flag);
}