/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:36:16 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/13 14:36:18 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(int _nb)
{
	int		count;
	long	nb;

	nb = _nb;
	count = 1;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_count_digit_u(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_count_hex_digits(unsigned long nb)
{
	int	len;

	len = 1;
	while (nb > 0xf)
	{
		++len;
		nb /= 16;
	}
	return (len);
}
