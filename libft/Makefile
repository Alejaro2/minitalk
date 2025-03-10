# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 09:37:54 by alejaro2          #+#    #+#              #
#    Updated: 2025/03/10 09:37:56 by alejaro2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar -rcs
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/ft_bzero.c src/ft_strchr.c src/ft_memcmp.c src/ft_memmove.c src/ft_isdigit.c src/ft_isalpha.c src/ft_putnbr_fd.c src/ft_itoa.c src/ft_atoi.c src/ft_isascii.c src/ft_isalnum.c src/ft_striteri.c src/ft_strncmp.c src/ft_memchr.c src/ft_strlen.c src/ft_strlcpy.c src/ft_isprint.c src/ft_strrchr.c src/ft_strnstr.c src/ft_substr.c src/ft_strjoin.c src/ft_strdup.c src/ft_calloc.c src/ft_strmapi.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_memcpy.c src/ft_strtrim.c src/ft_putendl_fd.c src/ft_strlcat.c src/ft_memset.c src/ft_toupper.c src/ft_tolower.c src/ft_split.c \
      ft_printf/src/ft_printf.c ft_printf/src/ft_print_char.c ft_printf/src/ft_print_hexadecimal.c ft_printf/src/ft_print_num.c ft_printf/src/ft_print_pointer.c ft_printf/src/ft_print_str.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) include/libft.h ft_printf/include/ft_printf.h
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -Ift_printf/include -o $@ $< -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re