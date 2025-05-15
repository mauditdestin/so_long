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
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/* */
# define SPRITE_SIZE 64
# define FPS 100000

typedef struct s_data {
	t_textures	texture;
	char		**map;
	char		**check_map;
	int			size_y;
	int			size_x;
	int			cur_y;
	int			cur_x;
	int			movements;
}	t_data;
typedef	struct s_textures
{
	void	*ground;
	void	*coin;
	void	*wall;
	void	*door;
}		t_textures;

// MOVEMENTS
void	up(t_data *data);
void	down(t_data *data);
void	right(t_data *data);
void	left(t_data *data);