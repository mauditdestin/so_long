/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:04:14 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/15 12:04:14 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	up(t_data *data)
{
	if (movement_check_walls(data, data->cur_y - 1, data->cur_x))
	{
		(data->cur_y)--;
		(data->movements)++;
		data->image.play->instances[0].y -= SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}

void	down(t_data *data)
{
	if (movement_check_walls(data, data->cur_y + 1, data->cur_x))
	{
		(data->cur_y)++;
		(data->movements)++;
		data->image.play->instances[0].y += SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}

void	left(t_data *data)
{
	if (movement_check_walls(data, data->cur_y, data->cur_x - 1))
	{
		(data->cur_x)--;
		(data->movements)++;
		data->image.play->instances[0].x -= SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}

void	right(t_data *data)
{
	if (movement_check_walls(data, data->cur_y, data->cur_x + 1))
	{
		(data->cur_x)++;
		(data->movements)++;
		data->image.play->instances[0].x += SPRITE_SIZE;
		ft_printf("| Movement : %i\n", data->movements);
		movement_check_collectible(data);
		movement_check_exit(data);
		usleep(FPS);
	}
}
