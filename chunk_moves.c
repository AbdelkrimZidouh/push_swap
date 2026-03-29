/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:33:03 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:37:33 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_stack_node **a, int pos)
{
	int	len;
	int	steps;

	len = stack_len(*a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ft_rotate_sa(a, true);
	}
	else
	{
		steps = len - pos;
		while (steps-- > 0)
			ft_reverse_rotate_sa(a, true);
	}
}

void	move_to_top_b(t_stack_node **b, int pos)
{
	int	len;
	int	steps;

	len = stack_len(*b);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ft_rotate_sb(b, true);
	}
	else
	{
		steps = len - pos;
		while (steps-- > 0)
			ft_reverse_rotate_sb(b, true);
	}
}
