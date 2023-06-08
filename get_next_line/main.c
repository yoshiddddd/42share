/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:05:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/08 10:00:08 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	int 	fd2;
	int 	fd3;
	char	*line;

	line = "";
	fd = open("test.txt", O_RDONLY);
	fd2 = open("text2.txt",O_RDONLY);		
	fd3 = open("text3.txt",O_RDONLY);
	
	if(fd < 0)
	{
		printf("open error\n");
	}
	// while (line)
	// {
				line = get_next_line(fd);
		line = get_next_line(fd2);
		line = get_next_line(fd3);



		line = get_next_line(fd);
		printf("> %s\n", line);
		line = get_next_line(fd2);
		printf("> %s\n", line);
		line = get_next_line(fd3);
		printf("> %s\n", line);
		free(line);
	// }
	return (0);
}