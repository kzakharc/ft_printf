#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 13:41:05 by kzakharc          #+#    #+#              #
#    Updated: 2017/05/14 17:52:14 by kzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c tp_f.c tp_s.c ft_it_base.c wid_prec.c else.c for_print.c      \
      all_for_flags.c for_bs.c
OBJECT = $(SRC:.c=.o)
LIBFT = ./libft/ft_memset.o		\
		./libft/ft_bzero.o		\
		./libft/ft_memcpy.o		\
		./libft/ft_memccpy.o	\
		./libft/ft_memmove.o	\
		./libft/ft_memchr.o		\
		./libft/ft_memcmp.o		\
		./libft/ft_strlen.o		\
		./libft/ft_strdup.o		\
		./libft/ft_strcpy.o		\
		./libft/ft_strncpy.o	\
		./libft/ft_strcat.o		\
		./libft/ft_strncat.o	\
		./libft/ft_strlcat.o	\
		./libft/ft_strchr.o		\
		./libft/ft_strrchr.o	\
		./libft/ft_strstr.o		\
		./libft/ft_strnstr.o	\
		./libft/ft_strcmp.o		\
		./libft/ft_strncmp.o	\
		./libft/ft_atoi.o		\
		./libft/ft_isalpha.o	\
		./libft/ft_isdigit.o	\
		./libft/ft_isalnum.o	\
		./libft/ft_isascii.o	\
		./libft/ft_isprint.o	\
		./libft/ft_toupper.o	\
		./libft/ft_tolower.o	\
		./libft/ft_memalloc.o	\
		./libft/ft_memdel.o		\
		./libft/ft_strnew.o		\
		./libft/ft_strdel.o		\
		./libft/ft_strclr.o		\
		./libft/ft_striter.o	\
		./libft/ft_striteri.o	\
		./libft/ft_strmap.o		\
		./libft/ft_strmapi.o	\
		./libft/ft_strequ.o		\
		./libft/ft_strnequ.o	\
		./libft/ft_strsub.o		\
		./libft/ft_strjoin.o	\
		./libft/ft_strtrim.o	\
		./libft/ft_strsplit.o	\
		./libft/ft_itoa.o		\
		./libft/ft_putchar.o	\
		./libft/ft_putstr.o		\
		./libft/ft_putendl.o	\
		./libft/ft_putnbr.o		\
		./libft/ft_putchar_fd.o	\
		./libft/ft_putstr_fd.o	\
		./libft/ft_putendl_fd.o	\
		./libft/ft_putnbr_fd.o	\
		./libft/ft_lstnew.o		\
		./libft/ft_lstdelone.o	\
		./libft/ft_lstdel.o		\
		./libft/ft_lstadd.o		\
		./libft/ft_lstiter.o	\
		./libft/ft_lstmap.o		\
		./libft/ft_cntwords.o	\
		./libft/ft_countdigits.o\
		./libft/ft_isspace.o	\
		./libft/ft_isspace_s.o	\

.PHONY: libft.a

all: $(NAME)
$(NAME): libft.a $(OBJECT)
	ar rc $(NAME) $(OBJECT) $(LIBFT)
	ranlib $(NAME)
libft.a:
	make -C ./libft
%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJECT)
	make clean -C ./libft
fclean: clean
	rm -f $(NAME) libft/libft.a
re: fclean all