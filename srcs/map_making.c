/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_making.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:04:02 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/02 16:04:02 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_commands(void *param)
{
	t_data *data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx, MLX_KEY_W))
		up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx, MLX_KEY_S))
		down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(data->mlx, MLX_KEY_D))
		right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->mlx, MLX_KEY_A))
		left(data);	
}

void map_making(t_data *data)
{
	data->mlx = mlx_init(data->size_y * SPRITE_SIZE, data->size_y * SPRITE_SIZE, "So long", true);
	if (!(data->mlx))
		error_exit(data, "Window couldn't be created");
}