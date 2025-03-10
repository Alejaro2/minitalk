# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 09:44:57 by alejaro2          #+#    #+#              #
#    Updated: 2025/03/10 10:10:50 by alejaro2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDE_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c

OBJ_SERVER = $(SERVER_SRC:.c=.o)
OBJ_CLIENT = $(CLIENT_SRC:.c=.o)

# Colores para la terminal
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "$(GREEN)Compilando: $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)
	@echo "$(GREEN)Servidor compilado correctamente!$(RESET)"

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)
	@echo "$(GREEN)Cliente compilado correctamente!$(RESET)"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@echo "$(RED)Objetos eliminados!$(RESET)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(RED)Ejecutables eliminados!$(RESET)"

re: fclean all

.PHONY: all clean fclean re