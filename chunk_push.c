/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:30:29 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:37:50 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_push(t_stack_node **a, t_stack_node **b,
						int *pushed, int chunk_size)
{
	if ((*a)->index <= *pushed)
	{
		ft_push_to_sb(a, b, true);
		ft_rotate_sb(b, true);
		(*pushed)++;
	}
	else if ((*a)->index <= *pushed + chunk_size)
	{
		ft_push_to_sb(a, b, true);
		(*pushed)++;
	}
	else
		return (0);
	return (1);
}

void	push_chunks(t_stack_node **a, t_stack_node **b)
{
	int	pushed;
	int	chunk_size;
	int	target_pos;

	pushed = 0;
	chunk_size = get_chunk_size(stack_len(*a));
	while (*a)
	{
		if (handle_push(a, b, &pushed, chunk_size))
			continue ;
		target_pos = find_target_pos(*a, pushed + chunk_size);
		if (target_pos >= 0)
			move_to_top_a(a, target_pos);
	}
}

void	push_back(t_stack_node **a, t_stack_node **b)
{
	int	pos;

	while (*b)
	{
		pos = find_max_pos(*b);
		move_to_top_b(b, pos);
		ft_push_to_sa(a, b, true);
	}
}
