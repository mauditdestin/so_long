/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:36:35 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:36:38 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include "unistd.h"

int main(int argc, char **argv)
{
	int values = ft_isdigit(48);
	if (values == 1)
	{
		write(1, "1", 1);
		return (1);
	}
	write(1, "0", 1);
	return(0);
}
*/
