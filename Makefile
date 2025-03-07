# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 15:18:25 by alejaro2          #+#    #+#              #
#    Updated: 2025/03/07 15:19:39 by alejaro2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
PRINTF_DIR = $(LIBFT_DIR)/printf
LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a  # Añadimos libft.a por si existe

SERVER_SRC = src/server.c

all: $(LIBFT_DIR) $(LIBFTPRINTF) $(NAME_SERVER)

$(LIBFTPRINTF):
	make -C $(PRINTF_DIR)

$(NAME_SERVER): $(SERVER_SRC) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_SRC) -L$(PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(NAME_SERVER)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean 
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re