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

/* Define the keyboard keys */
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_ESCAPE 65307

typedef	struct s_map
{
	int		height;
	int		width;
	int		player_spot;
	int		player_count;
	int		exit_spot;
	int		exit_count;
	int		sum_lines;
	int		sum_colums;
	int		collect_count;
	int		check_collect_count;
	char	*check_map;
	char	*play_map;
	int		check_exit_reach;
}		t_map;
typedef	struct s_textures
{
	
}		t_textures;
typedef	struct s_player
{
	
}		t_player;
typedef	struct s_game
{
	t_map		map;
	t_textures	textures;
	t_player	player;
	void		*mlx;
	void		*win2;
}		t_game;


// RESSOURCES
void	free_r(t_game *game);
int		close_window(void *p);