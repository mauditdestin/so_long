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

typedef	struct s_textures
{
	void	*ground;
	void	*coin;
	void	*wall;
	void	*door;
}		t_textures;
typedef	struct s_player
{
	void	*player_idle;
}		t_player;
typedef	struct s_game
{
	t_textures	textures;
	t_player	player;
	void		*mlx;
	void		*window;
	int			score;
	int			coins;
	int			moves;
	int			height;
	int			width;
	int			x;
	int			y;
	int			map_rows;
	int			map_cols;
	int			exit_row;
	int			exit_col;
	int			flood_fill_coins;
	int			current_frames;
	int			player_position;
	char		**map;
}		t_game;
