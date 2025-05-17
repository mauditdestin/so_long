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
	if (data->map[x][y] == '1')
		return (0);
	return (1);
}

// Vérifie si le joueur est sur la sortie et s'il a collecté toutes les gems : si oui, il peut quitter.
// Sinon, affiche un message s’il manque des gems. Si le joueur est sur un ennemi, il meurt et le jeu se ferme.
void	movement_check_exit(t_data *data)
{
	if (data->map[data->cur_x][data->cur_y] == 'E' && data->collected_gems == data->total_gems)
	{
		ft_printf("You escaped with all the gems !\n");
		mlx_close_window(data->mlx);
	}
	else if (data->map[data->cur_x][data->cur_y] == 'E')
		ft_printf("|\n| You still have gems to collect before leaving!\n");
	else if (data->map[data->cur_x][data->cur_y] == 'T')
	{
		ft_printf("You've been killed by an ennemy !\n");
		mlx_close_window(data->mlx);
	}
}

void	movement_check_collectible(t_data *data)
{

}