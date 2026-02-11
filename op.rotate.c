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

void ft_rotate_sa(t_stack_node **stack_a)
{
    t_stack_node *first ;  
    t_stack_node *last ;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;

    first = (*stack_a) ;
    (*stack_a) = first->next ;
    (*stack_a)->prev = NULL ;

    last = ft_lstlast(*(stack_a)) ;
    first->next = NULL ;
    first->prev = last ;

    last->next = first ;
}
