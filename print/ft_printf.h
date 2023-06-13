/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/13 18:44:05 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	    ft_output(va_list args,const char *format);
int		ft_itoa(int n);
int	    ft_putchar(char c);
int 	ft_putstr(char *s);
int	    ft_putnbr_fd(int n);
size_t	ft_strlen(const char *s);
int     ft_putnbr_base(unsigned long long  nb, char *base);

int 	ft_unsconver(unsigned int i);
int ft_pointconver(unsigned long long  p);
int ft_hexconver(unsigned int i, char ident);
#endif