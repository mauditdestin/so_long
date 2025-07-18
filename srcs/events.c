/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:21:07 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/17 02:21:07 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Vérifie si la case aux coordonnées (x, y) est accessible.
// Retourne 1 si ce n’est pas un mur ('1'), sinon 0.
int	movement_check_walls(t_data *data, int y, int x)
{
	return (!(data->map[y][x] == '1'));
}

// Désactive l'instance d'une gemme selon sa couleur 
// et son index pour la retirer visuellement du jeu.
static void	delete_gem_sprite(t_data *data, char gem_color, int gem_instance)
{
	if (gem_color == 'G')
		data->image.ggem->instances[gem_instance].enabled = false;
	if (gem_color == 'B')
		data->image.bgem->instances[gem_instance].enabled = false;
	if (gem_color == 'W')
		data->image.wgem->instances[gem_instance].enabled = false;
	if (gem_color == 'R')
		data->image.rgem->instances[gem_instance].enabled = false;
}

// Compte les occurrences d'une gemme jusqu'à la position actuelle du joueur
// puis supprime la gemme correspondante via delete_gem_sprite.
void	remove_gem(t_data *data)
{
	t_gem	gem;

	gem.y = 0;
	gem.x = 0;
	gem.gem_instance = -1;
	gem.gem_color = data->map[data->cur_y][data->cur_x];
	while (gem.y <= data->cur_y)
	{
		if (gem.y == data->cur_y)
		{
			while (gem.x <= data->cur_x)
				if (data->map[gem.y][gem.x++] == gem.gem_color
					|| data->map[gem.y][gem.x - 1] == gem.gem_color + 32)
					gem.gem_instance++;
		}
		else
			while (gem.x <= data->size_x)
				if (data->map[gem.y][gem.x++] == gem.gem_color
					|| data->map[gem.y][gem.x - 1] == gem.gem_color + 32)
					gem.gem_instance++;
		gem.x = 0;
		gem.y++;
	}
	delete_gem_sprite(data, gem.gem_color, gem.gem_instance);
}

// Check si le joueur est sur une gemme (G, B, W, R).
// Si oui, on la ramasse, on met à jour la map, 
// on affiche le nombre de gemmes collectées,
// et on affiche un message spécial si toutes les gemmes ont été trouvées.
void	movement_check_collectible(t_data *data)
{
	if (data->map[data->cur_y][data->cur_x] == 'G'
		|| data->map[data->cur_y][data->cur_x] == 'B'
		|| data->map[data->cur_y][data->cur_x] == 'W'
		|| data->map[data->cur_y][data->cur_x] == 'R')
	{
		remove_gem(data);
		data->map[data->cur_y][data->cur_x] += 32;
		(data->collectible_i)++;
		ft_printf("|\tGems : %i\n", data->collectible_i);
		if (data->collectible_i == data->collectible_amount)
			ft_printf("|\t\tYou find all gems ! Find the exit\n");
	}
}

// Vérifie si le joueur est sur la sortie et s'il a collecté 
// toutes les gems : si oui, il peut quitter.
// Sinon, affiche un message s’il manque des gems. 
// Si le joueur est sur un ennemi, il meurt et le jeu se ferme
void	movement_check_exit(t_data *data)
{
	if (data->map[data->cur_y][data->cur_x] == 'E'
		&& data->collectible_i == data->collectible_amount)
	{
		ft_printf("| You flee with all the gems !\n");
		mlx_close_window(data->mlx);
	}
	else if (data->map[data->cur_y][data->cur_x] == 'E')
		ft_printf("|\n| Your greed keep you from exiting without all gems !\n");
	else if (data->map[data->cur_y][data->cur_x] == 'T')
	{
		ft_printf("|\n| You've been killed by a guard, Yikees !\n");
		mlx_close_window(data->mlx);
	}
}
