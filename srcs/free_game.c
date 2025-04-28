/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:53:11 by pleblond          #+#    #+#             */
/*   Updated: 2025/04/27 17:53:11 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int		i;


	i = 0;
	while(game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.player_idle);
}

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
}