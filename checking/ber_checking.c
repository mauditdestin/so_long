/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:02:38 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/03 02:02:38 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_doublon(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_printf("| Doublons Check :\n");
	while (y != data->size_y)
	{
		while (x != data->size_x)
		{
			fonctiontemp(data, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	error_doublon(data);
	ft_printf("|\tNo Doublons\n");
}

void	error_doublon(t_data *data)
{
	if (data->start_amount != 1)
		error_exit(data, "Must need 1 start.");
	if (data->total_gems == 0)
		error_exit(data, "Must need atleast 1 collectible.");
	if (data->exit_amount != 1)
		error_exit(data, "Must need 1 exit");
}

