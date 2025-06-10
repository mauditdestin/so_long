/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:13:15 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/05 16:13:15 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void create_frame(t_data *data, char *buf, int x, int y)
{
	while (buf[x] != '\n' && buf[x])
	{
		data->map[y][x] = buf[x];
		data->check_map[y][x] = '0';
		x++;
	}
	data->map[y][data->size_x] = 0;
	data->check_map[y][data->size_y] = 0;
}

static void	check_rectangle(t_data *data, char *buf, int fd)
{
	if ((int)ft_strlen(buf) - 1  != data->size_x)
	{
		while (buf)
		{
			free(buf);
			buf = get_next_line(fd);
		}
		close (fd);
		error_exit(data, "Map isn't rectangle.");
	}
}

void map_create(t_data *data, char *filepath)
{
	int		y;
	int		x;
	int		fd;
	char	*buf;

	y = 0;
	fd = open(filepath, O_RDONLY);
	while (y != data->size_y)
	{
		x = 0;
		buf = get_next_line(fd);
		check_rectangle(data, buf, fd);
		create_frame(data, buf, x, y);
		y++;
		free(buf);
	}
	buf = get_next_line(fd);
	free(buf);
	close(fd);
}