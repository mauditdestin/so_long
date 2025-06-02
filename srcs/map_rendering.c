/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:15:25 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/03 01:15:25 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_collectible2(t_data *data, int y, int x, int gem_color)
{
	if (gem_color == 3)
	{
		mlx_image_to_window(data->mlx, data->image.wgem,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'W';
	}
	if (gem_color == 1)
	{
		mlx_image_to_window(data->mlx, data->image.rgem,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'R';
	}
	put_collectible2(data, y, x, gem_color);
}


static void	put_collectible(t_data *data, int y, int x)
{
	int gem_color;

	gem_color = rand() % 4;
	if (gem_color == 0)
	{
		mlx_image_to_window(data->mlx, data->image.ggem,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'G';
	}
	if (gem_color == 1)
	{
		mlx_image_to_window(data->mlx, data->image.bgem,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
		data->map[y][x] = 'B';
	}
	put_collectible2(data, y, x, gem_color);
}