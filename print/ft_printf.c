/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:48:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/14 19:24:59 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_printf(const char *format, ...)
// {
// 	va_list	args;
// 	int		ans;

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
