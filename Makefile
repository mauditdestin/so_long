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

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)

SRCS_BONUS = $(wildcard srcs_bonus/*.c)

MLX_DIR = mlx

MLX_lib 