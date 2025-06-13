/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:22:10 by aallou-v          #+#    #+#             */
/*   Updated: 2025/06/13 14:39:20 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!s1 && !len)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] && (i + j) < len)
		{
			j++;
			if (!s2[j])
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(int argc, char **argv) {
	printf("%s\n", ft_strnstr("cououaisssno", "n", 12));
}
*/
