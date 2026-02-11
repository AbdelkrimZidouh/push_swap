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
#include "libft/libft.h"

void    ft_swap_sa(t_stack_node **stack_a, bool print)
{
    t_stack_node *first ;
    t_stack_node *seconde ;

    if(!stack_a || !(*stack_a) || !((*stack_a)->next))
        return ;
    
    first = (*stack_a) ;
    seconde = first->next ;

    first->next = seconde->next ;
    if (seconde->next)
        seconde->next->prev = first; 
    seconde->next = first ;
    seconde->prev = NULL ;
    first->prev = seconde ;

    (*stack_a) = seconde ; 
    if (print)
        ft_putstr_fd("sa\n", 2) ;
}
void ft_swap_sb(t_stack_node **stack_b, bool print)
{
    ft_swap_sa(stack_b, false) ;
    if (print)
        ft_putstr_fd("sb\n", 2) ;
}

void ft_swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
    ft_swap_sa(stack_a, false) ;
    ft_swap_sb(stack_b, false) ;
    ft_putstr_fd("ss\n", 2) ;
}