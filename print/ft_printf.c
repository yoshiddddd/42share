/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:48:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 20:02:52 by kyoshida         ###   ########.fr       */
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
	// char *s ="zxyasd";
	count = 0;
	count2 = 0;
	count = ft_printf("[%-+19.15d,%- 10.5d, %+.0d, %+-10.1d, %10c, %-10.p,%-20p]\n",12345,333,0,9,'\0',"1111",NULL);
		// count = ft_printf("[%- 10.5d]",333);
	// count = ft_printf("[%-12.p %%d]", "1234");

	printf("\n");
	printf("%d", count);
	printf("\n");
	count2 = printf("[%-+19.15d,%- 10.5d, %+.0d, %+-10.1d, %10c, %-10.p,%-20p, %#20.15x]", 12345,333,0,9,'\0',"1111",NULL,1234);
// count2 =	printf("[%-12.p %%d]", "1234");
	printf("\n");
	printf("%d", count2);
	printf("\n");
	return (0);
}
