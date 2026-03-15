/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:39:39 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/11 19:39:41 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack_node *min_node(t_stack_node *stack)
{
    t_stack_node *min_node ;

    if (!stack)
        return NULL;
    min_node = stack ;
    while (stack)
    {
        if (min_node->nbr > stack->nbr)
            min_node = stack ;
        stack = stack->next ;
    }
    return min_node ;
}

void assign_index(t_stack_node *stack)
{
    t_stack_node *tmp;
    t_stack_node *min;
    int idx = 0;

    while (idx < stack_len(stack))
	{
		min = stack ;
		tmp = stack ;
		while (tmp)
		{
			if (tmp->index == -1 && tmp->nbr < min->nbr)
    			min = tmp;
			tmp = tmp->next;
		}
		min->index = idx++ ;
	}
	
}
