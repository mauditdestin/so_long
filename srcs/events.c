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

// Désactive l'instance d'une gemme selon sa couleur et son index pour la retirer visuellement du jeu.
static void delete_gems_sprite(t_data *data, char gem_color, int gem_instance)
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

// Cette fonction doit trouver quelle instance exacte d'une gemme doit être supprimée sur la map.
// 1. Récupérer la couleur de la gemme sous le joueur.
// 2. Parcourir la map depuis le haut gauche jusqu'à la position actuelle du joueur.
// 3. À chaque fois qu'on trouve une gemme de la même couleur (majuscule ou minuscule), on incrémente un compteur.
// 4. Ce compteur correspond au numéro d'instance du sprite à supprimer.
// 5. Appeler delete_gem_sprite() avec la couleur et le numéro d'instance pour supprimer le bon sprite.
void	remove_gem(t_data *data)
{
	
}

// Check si le joueur est sur une gemme (G, B, W, R).
// Si oui, on la ramasse, on met à jour la map, on affiche le nombre de gemmes collectées,
// et on affiche un message spécial si toutes les gemmes ont été trouvées.
void	movement_check_collectible(t_data *data)
{
	if (data->map[data->cur_y][data->cur_x] == 'G'
		|| data->map[data->cur_y][data->cur_x] == 'W'
		|| data->map[data->cur_y][data->cur_x] == 'B'
		|| data->map[data->cur_y][data->cur_x] == 'R')
	{
		remove_gem(data);
		data->map[data->cur_y][data->cur_x] += 32;
		(data->collected_gems)++;
		ft_printf("|\tGems: %i\n", data->collected_gems);
		if (data->collected_gems == data->total_gems)
			ft_printf("|\tYou find all gems! Find the exit\n");
	}
}

