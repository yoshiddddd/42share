/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:30:13 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/07 23:32:43 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	num;

	if (!s)
		return (0);
	num = 0;
	while (s[num] != '\0')
		num++;
	return (num);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_s;
	int		i;

	i = 0;
	concat_s = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concat_s == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (*s1 != '\0')
			concat_s[i++] = *s1++;
	}
	if (s2 != NULL)
	{
		while (*s2 != '\0')
			concat_s[i++] = *s2++;
	}
	concat_s[i] = '\0';
	return (concat_s);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*s2;

	if (!s)
		return (NULL);
	ch = (char)c;
	s2 = (char *)s;
	while (*s2 != '\0')
	{
		if (*s2 == ch)
			return (s2);
		s2++;
	}
	return (NULL);
}