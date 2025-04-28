/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:50:57 by pleblond          #+#    #+#             */
/*   Updated: 2025/04/27 17:50:57 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	free_r(game);
	exit(0);
}

int print_error(t_game *game, char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len] != '\0')
		len++;
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, len);
	close_window(game);
	exit (1);
}

void	put_error_message(t_game *game, char *msg)
{
	char *error_message;
	int		i;

	error_message = "Error\nFailed to load collect image: ";
	i = 0;
	while (error_message != '\0')
	{
		write(2, &error_message[i], 1);
		i++;
	}
	i = 0;
	while (msg[i] != '\0')
	{
		write(2, msg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	close_window(game);
}