/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_checking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 00:20:31 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/09 00:20:31 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	putmap(t_data *data)
{
	int	y;

	ft_printf("|\n| Map created :\n");
	y = 0;
	while (y != data->size_y)
		ft_printf("|\t\t%s\n", data->map[y++]);
}

void	check_walls(t_data *data)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	ft_printf("|  Border walls check :\n");
	while (data->map[0][x])
		if (data->map[0][x++] != '1')
			error_exit(data, "Border walls aren't closed");
	x = 0;
	while (y != data->size_y - 1)
	{
		if (data->map[y][0] != '1' || data->map[y][data->size_x - 1] != '1')
			error_exit(data, "Border walls aren't closed");
		y++;
	}
	while (data->map[y][x])
		if (data->map[y][x++] != '1')
			error_exit(data, "Border walls aren't closed");
	ft_printf("|\tBorder walls are closed\n");
}

// FUNCTIONS BELOW ARE FOR CHECKING IS THE MAP IS POSSIBLE

static int is_checked(t_data *data, int y, int x)
{
	return (data->check_map[y][x] == '1');
}

static void	count_element(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'C')
		(data->collectible_i)++;
	if (data->map[y][x] == 'E')
		(data->exit_i)++;
	data->check_map[y][x] = '1';
}

int	check_is_possible(t_data *data, int y, int x)
{
	int	result[4];

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	count_element(data, y, x);
	if (data->exit_i >= 1 && data->collectible_amount == data->collectible_i)
		return (1);
	if (x < 0 || x >= data->size_x || y < 0 || y >= data->size_y
		|| data->map[y][x] == '1' || data->map[y][x] == 'T')
		return (0);
	if (data->map[y][x + 1] != '1' && !is_checked(data, y, x + 1))
		result[0] = check_is_possible(data, y, x + 1);
	if (data->map[y][x - 1] != '1' && !is_checked(data, y, x - 1))
		result[1] = check_is_possible(data, y, x - 1);
	if (data->map[y + 1][x] != '1' && !is_checked(data, y + 1, x))
		result[2] = check_is_possible(data, y + 1, x);
	if (data->map[y - 1][x] != '1' && !is_checked(data, y - 1, x))
		result[3] = check_is_possible(data, y - 1, x);
	return (result[0] || result[1] || result[2] || result[3]);
}