/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/11 17:26:14 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char ident, va_list args)
{
	int	count;

	count = 0;
	if (ident == 'c')
		count = ft_putchr(va_arg(args, char));
	else if (ident == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (ident == 'd' || ident == 'i')
		count = ft_putdig(va_arg(args, int));
	else if (ident == 'p')
		count = ft_hexconver(va_arg(args,unsigned long),void*);
	else if (ident == 'u')
		count = ft_unsconver(va_arg(args,unsigned long));
	else if (ident == 'x' || idet == 'X')
		count = 
	else if(ident == '%')
}

void	ft_output(va_list args, char *format)
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
			ft_putchar(va_arg(args,char))
			count += 1;
		}

		i++;
	}
}