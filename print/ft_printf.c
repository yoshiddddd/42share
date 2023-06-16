/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:48:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/15 13:35:19 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		ans;
	// if(format == NULL)
	// return -1;

// 	va_start(args, format);
// 	ans = ft_judgment(args, format);
// 	va_end(args);
// 	return (ans);
// }

int	main(void)
{
	// int	count;
	int	count2;

	// count = 0;
	count2 = 0;
	// count = ft_printf("%u", UINT_MAX);
	printf("\n");
	count2 = printf("%c", 'a');
	printf("\n");
	// printf("%d", count);
	printf("\n");
	printf("%d", count2);
	return (0);
}
