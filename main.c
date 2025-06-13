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

#include "includes/so_long.h"

static void	free_data(t_data *data)
{
	int	i;

	if (data->check_map || data->map)
	{
		i = 0;
		while (i != data->size_y)
		{
			free(data->check_map[i]);
			free(data->map[i]);
			i++;
		}
		free(data->check_map);
		free(data->map);
	}
	free(data);
}

void error_exit(t_data *data, char *erreur)
{
	free_data(data);
	ft_printf("|\tError\n---> %s\n", erreur);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	t_data *data;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	ber_check(argc, argv, data);
	map_making(data);
	free_data(data);
	ft_printf("|\n| Window closed, good bye !\n");
	ft_printf("+--------------------\n");
	return (0);
}