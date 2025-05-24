/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:04:17 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/15 17:04:17 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void load_textures(t_data *data)
{
	ft_printf("| Loading textures :\n");
	data->texture.back = mlx_load_png("../sprites/floor_sprite.png");
	data->image.back = mlx_texture_to_image(data->mlx, data->texture.back);

	data->texture.wall = mlx_load_png("../sprites/wall_sprite.png");
	data->image.wall = mlx_texture_to_image(data->mlx, data->texture.wall);

	data->texture.play = mlx_load_png("../sprites/player_sprite.png");
	data->image.play = mlx_texture_to_image(data->mlx, data->texture.play);

	data->texture.exit = mlx_load_png("../sprites/exit_sprite.png");
	data->image.exit = mlx_texture_to_image(data->mlx, data->texture.exit);

	data->texture.bgem = mlx_load_png("../sprites/blue_gem.png");
	data->image.bgem = mlx_texture_to_image(data->mlx, data->texture.bgem);

	data->texture.ggem = mlx_load_png("../sprites/green_gem.png");
	data->image.ggem = mlx_texture_to_image(data->mlx, data->texture.ggem);

	data->texture.wgem = mlx_load_png("../sprites/white_gem.png");
	data->image.wgem = mlx_texture_to_image(data->mlx, data->texture.wgem);

	data->texture.rgem = mlx_load_png("../sprites/red_gem.png");
	data->image.rgem = mlx_texture_to_image(data->mlx, data->texture.rgem);

	data->texture.skeleton = mlx_load_png("../sprites/skeleton_sprite.png");
	data->image.skeleton = mlx_texture_to_image(data->mlx, data->texture.skeleton);
	ft_printf("|\tTextures loaded\n|\n");
}

void destroy_texture(t_data *data)
{
	mlx_delete_texture(data->texture.back);
	mlx_delete_image(data->mlx, data->image.back);

	mlx_delete_texture(data->texture.wall);
	mlx_delete_image(data->mlx, data->image.wall);

	mlx_delete_texture(data->texture.play);
	mlx_delete_image(data->mlx, data->image.play);

	mlx_delete_texture(data->texture.exit);
	mlx_delete_image(data->mlx, data->image.exit);

	mlx_delete_texture(data->texture.ggem);
	mlx_delete_image(data->mlx, data->image.ggem);

	mlx_delete_texture(data->texture.bgem);
	mlx_delete_image(data->mlx, data->image.bgem);

	mlx_delete_texture(data->texture.wgem);
	mlx_delete_image(data->mlx, data->image.wgem);

	mlx_delete_texture(data->texture.rgem);
	mlx_delete_image(data->mlx, data->image.rgem);

	mlx_delete_texture(data->texture.skeleton);
	mlx_delete_image(data->mlx, data->image.skeleton);
}