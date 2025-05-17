/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:48:42 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/17 18:48:42 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Alloue dynamiquement la mémoire pour la map du jeu et une copie utilisée pour les vérifications.
// Chaque ligne est une chaîne de caractères de taille size_x + 1 (pour le '\0').
static void	map_malloc(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * data->size_y);
	data->check_map = malloc(sizeof(char *) * data->size_y);
	while (i != data->size_y)
	{
		data->map[i] = malloc(sizeof(char) * data->size_x + 1);
		data->check_map[i++] = malloc(sizeof(char) * data->size_x + 1);
	}
}