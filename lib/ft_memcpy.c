/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:37:52 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:37:54 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cd;
	unsigned char	*cs;

	i = -1;
	cd = (unsigned char *) dest;
	cs = (unsigned char *) src;
	if (cd == NULL && cs == NULL)
		return (NULL);
	while (++i < n)
		cd[i] = cs[i];
	return (dest);
}
