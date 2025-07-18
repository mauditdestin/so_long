/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:04:36 by pleblond          #+#    #+#             */
/*   Updated: 2025/04/27 17:04:36 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Lib for malloc, exit, write, and open */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <MLX42/MLX42.h>
#include "libft.h"

#define SPRITE_SIZE 64
#define FPS 100000

typedef struct s_gem
{
	int		y;
	int		x;
	char	gem_color;
	int		gem_instance;
}	t_gem;

typedef struct s_textures
{
	mlx_texture_t	*play;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*back;
	mlx_texture_t	*wgem;
	mlx_texture_t	*bgem;
	mlx_texture_t	*ggem;
	mlx_texture_t	*rgem;
	mlx_texture_t	*sklt;
}	t_textures;

typedef struct s_image
{
	mlx_image_t		*back;
	mlx_image_t		*play;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*wgem;
	mlx_image_t		*bgem;
	mlx_image_t		*ggem;
	mlx_image_t		*rgem;
	mlx_image_t		*sklt;
}	t_image;

typedef struct s_data
{
	mlx_t		*mlx;
	t_textures	texture;
	t_image		image;
	char		**map;
	char		**check_map;
	int			start_amount;
	int			size_y;
	int			size_x;
	int			cur_y;
	int			cur_x;
	int			movements;
	int			collectible_i;
	int			exit_i;
	int			exit_amount;
	int			collectible_amount;
}	t_data;

// MOVEMENTS
void	up(t_data *data);
void	down(t_data *data);
void	right(t_data *data);
void	left(t_data *data);

// CHECKING & MAKING
void	movement_check_exit(t_data *data);
int		movement_check_walls(t_data *data, int y, int x);
void	movement_check_collectible(t_data *data);
void	remove_gem(t_data *data);
void	map_making(t_data *data);
void	map_rendering(t_data *data);
void	map_create(t_data *data, char *filepath);
void	map_parsing(t_data *data, char *path);
void	putmap(t_data *data);
int		check_is_possible(t_data *data, int y, int x);
void	ber_check(int argc, char **argv, t_data *data);
void	check_walls(t_data *data);

// GRAPHISM
void	load_textures(t_data *data);
void	destroy_textures(t_data *data);

// ERROR
void	error_exit(t_data *data, char *erreur);
void	doublon_error(t_data *data);
