/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:34:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/18 17:29:30 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t	ft_strlen(const char *s)
{
	size_t	num;

	if (s == NULL)
		return (0);
	num = 0;
	while (s[num] != '\0')
		num++;
	return (num);
}

int ft_intlen(int nbr,t_flag *flag)
{
	int count;

	count =  0;

	if(nbr<0)
	{
			nbr*=-1;
		// if( flag->minus == 0)
		// 	count++;
	}
	while(nbr!= 0)
	{
		nbr=nbr/10;
		count++;
	}
	
	return (count);
}