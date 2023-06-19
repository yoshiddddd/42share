/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/19 12:28:04 by yoshidakazu      ###   ########.fr       */
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
int		ft_putnbr_fd(int n,t_flag *flag);
int		ft_putnbr_base(unsigned long long nb, char *base);
int	ft_putspace(int len);
int     put_sign(t_flag *flag,int nbr);
int put_zeros(t_flag *flag , int len);

//------------judgment_function-----------
int		ft_judgment(va_list args, const char *format);
int		ft_check(char ident, va_list args,t_flag *flag);
char	*ft_flag_check(const char *format, va_list args, t_flag *flag);
char	*ft_width_check(const char *format, va_list args, t_flag *flag);
char	*ft_precision_check(const char *format, va_list args, t_flag *flag);
int check_sign(int nbr,t_flag *flag);

//------------flag_function-----------
t_flag	ft_flag_init(void);

//------------libft_function--------------
size_t	ft_strlen(const char *s);
int ft_intlen(int nbr,t_flag *flag);
int	ft_atoi(const char *str);
int getnbr_base(unsigned long long nb , char *base);

//------------write_function--------------
int	ft_char_write(int args, t_flag *flag);
int	ft_str_write(char *s, t_flag *flag);
int ft_int_write(int nbr,t_flag *flag);
int		ft_ptr_write(unsigned long long p,t_flag *flag);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//---------conversion_function------------
int		ft_unsconver(unsigned int i);
int		ft_hexconver(unsigned int i, char ident);
#endif