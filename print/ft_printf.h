/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/16 13:29:44 by kyoshida         ###   ########.fr       */
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

typedef struct flag
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	star_width;
	int star_width_value;
	int star_precision;
	int star_precision_value;
	int	space;
	int	sharp;
	int	plus;
}		t_flag;

//------------ft_printf_function----------
int		ft_printf(const char *format, ...);


//------------put_function----------------
int		ft_putchar(char c);
int		ft_putstr(char *s,int writelen);
int		ft_putnbr_fd(int n);
int		ft_putnbr_base(unsigned long long nb, char *base);


//------------judgment_function-----------
int		ft_judgment(va_list args, const char *format);
int		ft_check(char ident, va_list args,t_flag *flag);

//------------flag_function-----------
t_flag	ft_flag_init(void)

//------------libft_function--------------
size_t	ft_strlen(const char *s);


//---------conversion_function------------
int		ft_unsconver(unsigned int i);
int		ft_pointconver(unsigned long long p);
int		ft_hexconver(unsigned int i, char ident);
#endif