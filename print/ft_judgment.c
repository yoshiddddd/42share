/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/12 21:50:46 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char ident, va_list args)
{
	int	count;

	count = 0;
	if (ident == 'c')
		count = ft_putstr(va_arg(args, char *));
	else if (ident == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (ident == 'd' || ident == 'i')
		count = ft_putnbr_fd(va_arg(args, int));
	else if (ident == 'p')
		count = ft_pointconver((unsigned long long)va_arg(args, void *));
	else if (ident == 'u')
		count = ft_unsconver(va_arg(args, unsigned long));
	else if (ident == 'x' || ident == 'X')
		count = ft_hexconver(va_arg(args, unsigned int), ident);
	else if (ident == '%')
		count = ft_putchar(ident);
	return (count);
}

int	ft_output(va_list args, char *format)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_check(format[i + 1], args);
			i++;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
		if (format[i] == NULL)
			return (count);
	}
	return (count);
}
