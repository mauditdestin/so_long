/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:36:11 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:36:13 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (0);
	while (i != nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
