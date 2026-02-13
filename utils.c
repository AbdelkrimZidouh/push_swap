/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:42:54 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/11 19:42:56 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long	ft_atol(const char *nptr)
{
	size_t	i;
	int		signe;
	long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (nbr > (LONG_MAX - (nptr[i] - '0')) / 10)
			return (signe == 1 ? LONG_MAX : LONG_MIN);
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * signe);
}
