/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:06:16 by pleblond          #+#    #+#             */
/*   Updated: 2025/04/27 17:06:16 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	move_player(int key, t_game *game)
{
	if (key == KEY_DOWN)
		return (game->map.sum_colums);
	else if (key == KEY_UP)
		return (-(game->map.sum_colums));
	else if (key == KEY_RIGHT)
	else if (key == KEY_LEFT)
}

void	handle_key(int key, t_game *game, int *delta)
{
	if (key == KEY_ESCAPE)
	{
		close_window(game);
		exit(0);
	}
	else if (can_move(key, game))
		*delta = move_player(key, game);
}