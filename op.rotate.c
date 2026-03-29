/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:09:02 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/07 18:09:04 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = find_last_node(*stack);
	first->next = NULL;
	last->next = first;
}

void	ft_rotate_sa(t_stack_node **stack_a, bool print)
{
	ft_rotate(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rotate_sb(t_stack_node **stack_b, bool print)
{
	ft_rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rotate_ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (print)
		write(1, "rr\n", 3);
}
