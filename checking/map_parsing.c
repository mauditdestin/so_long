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

// Vérifie que chaque caractère de la map est valide ('1', '0', 'P', 'C', 'E' ou 'T').
// Quitte le programme avec une erreur si un caractère inconnu est trouvé.
static void check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(y != data->size_y)
	{
		while(x != data->size_x)
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && data->map[y][x] != 'P'
				&& data->map[y][x] != 'C' && data->map[y][x] != 'E' && data->map[y][x] != 'T')
				error_exit(data, "Invalid character in map.");
			x++;
		}
		x = 0;
		y++;
	}
}

// Vérifie que le buffer de la map n’est pas vide après lecture du fichier.
// Si vide, libère les ressources, ferme le fichier et affiche une erreur.
static void check_and_free_map(t_data *data, char *buf, int fd)
{
	if (!buf)
	{
		free(buf);
		close(fd);
		error_exit(data, "There is nothing in the map.");
	}
}