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
#include "libft/libft.h"

static void ft_rotate(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    *stack = first->next;
    (*stack)->prev = NULL;

    last = ft_lstlast(*stack);
    first->next = NULL;
    first->prev = last;
    last->next = first;
}


void ft_rotate_sa(t_stack_node **stack_a, bool print)
{
    ft_rotate(stack_a);
    if (print)
        ft_putstr_fd("ra\n", 1);
}

void ft_rotate_sb(t_stack_node **stack_b, bool print)
{
    ft_rotate(stack_b);
    if (print)
        ft_putstr_fd("rb\n", 1);
}

void ft_rotate_ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    if (print)
        ft_putstr_fd("rr\n", 1);
}

