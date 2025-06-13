/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:36:41 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:36:43 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_isonly(char *s, char *charset)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_is_charset(s[i], charset))
			return (0);
	}
	return (1);
}
