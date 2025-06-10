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

// Affiche une gemme blanche ou rouge selon gem_color, et met à jour la map.
// Appelée depuis put_collectible pour gérer les gemmes 2 et 3.
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

// Tire une gemme aléatoire (verte, bleue, blanche ou rouge) et l'affiche sur la carte.
// Met à jour la case correspondante dans la map avec la lettre de la gemme.
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

// Affiche l’arrière-plan puis les sprites de la case (mur, sortie, ennemi, collectible...).
// Si la case contient un collectible, appelle la fonction pour l’afficher.
static void put_sprite(t_data *data, int y, int x)
{
	mlx_image_to_window(data->mlx, data->image.back,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == '1')
		mlx_image_to_window(data->mlx, data->image.wall,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == 'E')
		mlx_image_to_window(data->mlx, data->image.exit,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == 'T')
		mlx_image_to_window(data->mlx, data->image.skeleton,
				x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (data->map[y][x] == 'C')
			put_collectible(data, y, x);
}

// Parcourt toute la carte et appelle put_sprite pour afficher chaque case.
// Affiche ensuite le joueur à sa position actuelle.
void	map_rendering(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y != data->size_y)
	{
		x = 0;
		while (x != data->size_x)
		{
			put_sprite(data, y, x);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->image.play,
			data->cur_x * SPRITE_SIZE, data->cur_y * SPRITE_SIZE);
}