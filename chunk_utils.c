/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:31:59 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:37:33 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

int	find_target_pos(t_stack_node *stack, int max_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index <= max_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	find_max_pos(t_stack_node *stack)
{
	int	pos;
	int	max_pos;
	int	max_index;

	pos = 0;
	max_pos = 0;
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}
