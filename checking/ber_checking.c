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

static void	check_element(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'P')
	{
		(data->start_amount)++;
		data->cur_x = x;
		data->cur_y = y;
	}
	else if (data->map[y][x] == 'C')
			(data->collected_gems)++;
	else if (data->map[y][x] == 'E')
			(data->exit_amount)++;
}

static void	check_extension(t_data *data, char *filepath)
{
	char	*ext;
	int	fd;

	ft_printf("|\tExtension check:\n");
	ext = ft_strrchr(filepath, '.');
	if (!ext)
		error_exit(data, "Invalid map path.");
	if (ft_strncmp(ext, ".ber", ft_strlen(ext)) != 0 || ft_strlen(ext) != 4)
		error_exit(data, "This is not a .ber file.");
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error_exit(data, "The file doesn't exist.");
	}
	else
		close(fd);
	ft_printf("|\tGood Extension.\n");
}

