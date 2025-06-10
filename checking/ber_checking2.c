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

	ft_printf("|\n|Map created :\n");
	y = 0;
	while (y != data->size_y)
		ft_printf("|\t\t%s\n", data->map[y++]);
}