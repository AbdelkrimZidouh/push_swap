/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:01:08 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/07 17:01:11 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *second;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->next = first;
    second->prev = NULL;
    first->prev = second;

    *stack = second;
}

void ft_swap_sa(t_stack_node **stack_a, bool print)
{
    ft_swap(stack_a);
    if (print)
    write(1, "sa\n", 3);
}

void ft_swap_sb(t_stack_node **stack_b, bool print)
{
    ft_swap(stack_b);
    if (print)
    write(1, "sb\n", 3);
}

void ft_swap_ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    if (print)
    write(1, "ss\n", 3);
}
