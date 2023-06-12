/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:34:05 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/12 18:50:14 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char *)buf;
	c = (unsigned char)ch;
	if (!buf)
		return (NULL);
	while (n > 0)
	{
		*ptr++ = c;
		n--;
	}
	return (buf);
}

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*tmp;

	if (n > SIZE_MAX / size)
		return (NULL);
	tmp = (unsigned char *)malloc(n * size);
	if (tmp == NULL)
		return (NULL);
	if (n == 0 || size == 0)
		return (malloc(0));
	ft_memset(tmp, 0, n * size);
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	num;

	if (s == NULL)
		return (0);
	num = 0;
	while (s[num] != '\0')
		num++;
	return (num);
}

