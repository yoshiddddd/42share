/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:48:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 12:42:44 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ans;
	if(format == NULL)
	return -1;

	va_start(args, format);
	ans = ft_judgment(args, format);
	va_end(args);
	return (ans);
}

int	main(void)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	count = ft_printf("[%x]","a");
	printf("\n");
	count2 = printf("[%- #10.9x]", 1234567);
	printf("\n");
	printf("%d", count);
	printf("\n");
	printf("%d", count2);
	return (0);
}
