/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:09:51 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/14 19:00:37 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_putchar(char s)
{
	write(1,&s,1);
	return (1);
}

int 	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return(i);
}
