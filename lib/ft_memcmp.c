/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:37:46 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:37:47 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = -1;
	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	while (++i < n)
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
	return (0);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*test = "test";
	char	*test2 = 'test';
	int	values = ft_memcmp(test, test2, 5);
	printf("%i\n", values);
}
*/
