/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:34:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/13 18:31:48 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char *)buf;
	c = (unsigned char)ch;
	if (!buf)
		return (NULL);
	while (n > 0)
	{
		*ptr++ = c;
		n--;
	}
	return (buf);
}

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

