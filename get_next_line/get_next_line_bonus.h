#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
char  *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
