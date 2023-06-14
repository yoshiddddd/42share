# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 16:19:28 by kyoshida          #+#    #+#              #
#    Updated: 2023/06/14 15:01:46 by kyoshida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := lftprintf.a
RM := rm -f
SRCS := ft_printf.c ft_convert.c ft_judgment.c ft_put_chstr.c ft_putnbr_base.c ft_putnbr_fd.c\
ft_strlen.c 

OBJS :=$(SRCS:.c=.o)

$(NAME):$(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re