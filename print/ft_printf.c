/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:48:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/13 19:38:04 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf(const char *format, ...)
{
	va_list args;
	int ans;
	va_start(args,format);
	ans = ft_output(args,format);

	va_end(args);

	return ans;
}
int main(void)
{
	int count = 0;
	int count2 = 0;
	count =ft_printf("%u", UINT_MAX);
	printf("\n");
	count2 = printf("%u", UINT_MAX);
	printf("\n");
	printf("%d", count);
	printf("\n");
	printf("%d", count2);
	return (0);
}
