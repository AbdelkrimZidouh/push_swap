/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.reverse.rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:22:51 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/13 16:22:57 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "libft/libft.h"

static void ft_reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last ;

    if (!stack || !(*stack) || !(*stack)->next)
        return ;

    last = ft_lstlast(*stack) ;
    last->prev->next = NULL ;
    last->next = *stack ;
    (*stack)->prev = last ;

    last->prev = NULL ;
    *stack = last ;
}

void ft_reverse_rotate_sa(t_stack_node **stack_a, bool print)
{
    ft_reverse_rotate(stack_a) ;
    if (print)
        ft_putstr_fd("rra\n", 1) ;
}

void ft_reverse_rotate_sb(t_stack_node **stack_b, bool print)
{
    ft_reverse_rotate(stack_b) ;
    if (print)
        ft_putstr_fd("rrb\n", 1) ;
}

void ft_reverse_rotate_ss(t_stack_node **stack_a,t_stack_node **stack_b, bool print)
{
    ft_reverse_rotate(stack_a) ;
    ft_reverse_rotate(stack_b) ;
    if (print)
        ft_putstr_fd("rrr\n", 1) ;
}