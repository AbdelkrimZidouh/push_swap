/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:49:05 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/13 16:49:07 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void ft_push(t_stack_node **stack1, t_stack_node **stack2)
{   
    t_stack_node *node ;

    if (!stack1 || !(*stack1))
        return ;

    node = (*stack1) ;
    *stack1 = node->next ;

    if (*stack1)
        (*stack1)->prev = NULL;
    
    node->next = *stack2 ;
    if (*stack2)
        (*stack2)->prev = node ;

    node->prev = NULL ;
    *stack2 = node ;
}

void ft_push_to_sa(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    ft_push(stack_b, stack_a) ;
    if (print)
    write(1, "pa\n", 3) ;
}

void ft_push_to_sb(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    ft_push(stack_a, stack_b) ;
    if (print)
    write(1, "pb\n", 3) ;
}