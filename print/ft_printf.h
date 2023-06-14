/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/14 15:00:05 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_output(va_list args, const char *format);
int	ft_check(char ident, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_fd(int n);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base(unsigned long long nb, char *base);

int		ft_unsconver(unsigned int i);
int		ft_pointconver(unsigned long long p);
int		ft_hexconver(unsigned int i, char ident);
#endif