#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 11:02:22 by yzakharc          #+#    #+#              #
#    Updated: 2017/06/08 18:25:05 by kzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ :=	$(patsubst %.c,%.o,$(wildcard *.c))						\
		$(patsubst %.c,%.o,$(wildcard libft/*.c))				\

all : $(NAME)

$(NAME) : $(OBJ)
	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %c.
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf *.o
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME)

re : fclean  all