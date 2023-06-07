/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:05:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/07 18:46:56 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("test.txt", O_RDONLY);
	if(fd < 0)
	{
		printf("open error\n");
	}
	// while (line)
	// {
		
		line = get_next_line(fd);
		printf("> %s", line);
		line = get_next_line(fd);
		printf("> %s", line);
		line = get_next_line(fd);
		printf("> %s", line);
		free(line);
	// }
	return (0);
}