/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:48:02 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/07 23:39:27 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_output(char *save_string)
{
	int		i;
	char	*ans;

	i = 0;
	if (save_string[i] == '\0')
		return (NULL);
	while (save_string[i] != '\n' && save_string[i] != '\0')
		i++;
	ans = (char *)malloc(sizeof(char) * i + 2);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (save_string[i] != '\n' && save_string[i] != '\0')
	{
		ans[i] = save_string[i];
		i++;
	}
	if (save_string[i] == '\n')
		ans[i++] = '\n';
	ans[i] = '\0';
	return (ans);
}

static char	*ft_save(char *save_string)
{
	int		i;
	int		count;
	char	*save;

	i = 0;
	count = 0;
	while (save_string[i] != '\n' && save_string[i] != '\0')
		i++;
	if (save_string[i] == '\0')
	{
		free(save_string);
		return (NULL);
	}
	save = (char *)malloc(sizeof(char) * ft_strlen(save_string) - i + 1);
	if (!save)
		return (NULL);
	i++;
	while (save_string[i] != '\0')
		save[count++] = save_string[i++];
	save[count] = '\0';
	free(save_string);
	return (save);
}

static char	*ft_read(int fd, char *save_string)
{
	ssize_t	n_read;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	n_read = 1;
	while (ft_strchr(save_string, '\n') == NULL && n_read != 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[n_read] = '\0';
		tmp = save_string;
		save_string = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (save_string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save_string[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd>256)
		return (NULL);
	save_string[fd] = ft_read(fd, save_string[fd]);
	if (!save_string[fd])
		return (NULL);
	line = ft_output(save_string[fd]);
	save_string[fd] = ft_save(save_string[fd]);
	return (line);
}