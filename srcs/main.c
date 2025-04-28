/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:04:55 by pleblond          #+#    #+#             */
/*   Updated: 2025/04/27 17:04:55 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		if (save_map(argv[1], &game) == 1)
			exit(EXIT_FAILURE);
		game.mlx = mlx.init();
		game.window = mlx.new_window(game.mlx, (game.map_cols - 1) * 32), \
		(game.map_rows + 1) * 32, "so_long");
	}
	else
		write(1, "Not enough arguments.\n", 22);
	return (0);
}