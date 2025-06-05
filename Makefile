# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 20:02:10 by pleblond          #+#    #+#              #
#    Updated: 2025/04/27 20:02:10 by pleblond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g
MLXFLAGS = ./MLX42/build/libmlx42.a -I./MLX42/include -ldl -lglfw -pthread -lm
LDFLAGS = -Llib -lftprintf

SRC = $(wildcard *.c) \
	  $(wildcard checking/*.c) \
	  $(wildcard game/*.c)

OBJ = $(SRC:.c=.o)

all:
	@if ! test -d MLX42; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	cd MLX42 && cmake -B build && cmake --build build -j4
	@$(MAKE) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./MLX42/include -c $< -o $@

$(NAME): $(OBJ)
	cd lib && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

clean:
	cd lib && $(MAKE) clean
	$(RM) -f $(OBJ)
	$(RM) -rf MLX42/build

fclean: clean
	cd lib && $(MAKE) fclean
	$(RM) -f $(NAME)
	$(RM) -rf MLX42

re: fclean all

.PHONY: all clean fclean re