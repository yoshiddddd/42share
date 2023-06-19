/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:06:09 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/18 12:06:25 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_zeros(t_flag *flag , int len)
{
    int count;
    
        count = 0;
        if(len<0)
        return (0);
        while(len>0)
        {
            count +=ft_putchar('0');
            len--;
        }
    return (count);
}