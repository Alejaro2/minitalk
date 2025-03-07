# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 15:18:25 by alejaro2          #+#    #+#              #
#    Updated: 2025/03/07 18:07:02 by alejaro2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server

LIBFT_DIR = libft
PRINTF_DIR = $(LIBFT_DIR)/printf

LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a

SERVER_SRC = src/server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: libft ft_printf $(NAME_SERVER)

libft:
	@make -C $(LIBFT_DIR)

ft_printf: libft
	@make -C $(PRINTF_DIR)

$(NAME_SERVER): $(SERVER_OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(PRINTF_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@rm -f $(SERVER_OBJ)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME_SERVER)

re: fclean all

.PHONY: all libft ft_printf clean fclean re
