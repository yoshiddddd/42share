/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:03:52 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/12 21:33:35 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_calc(long n, char *ans, char *base)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		ans[0] = base[0];
		return (1);
	}
	while (n > 0)
	{
		ans[i] = base[n % ft_count(base)];
		n /= ft_count(base);
		i++;
	}
	return (i);
}

int	ft_count(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_count(base) < 2)
		return (1);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == '-' || base[j] == '+'
				|| base[0] == '-' || base[0] == '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	ans[100];
	int		i;
	int		len;
	long	nbr2;

	nbr2 = nbr;
	i = 0;
	if (ft_error(base) == 1)
		return ;
	else
	{
		len = ft_count(base);
		if (nbr2 < 0)
		{
			write(1, "-", 1);
			nbr2 = -nbr2;
		}
		i = ft_calc(nbr2, ans, base);
		while (--i >= 0)
			write(1, &ans[i], 1);
	}
}
