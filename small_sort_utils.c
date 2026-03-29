#include "push_swap.h"

static int find_min_pos(t_stack_node *stack_a)
{
    int pos ;
    int min_pos ;
    int min ;
    t_stack_node *tmp ;

    pos = 0 ;
    min_pos = 0 ;
    min = stack_a->nbr ;
    tmp = stack_a ;
    while (tmp)
    {
        if (tmp->nbr < min)
        {
            min = tmp->nbr ;
            min_pos = pos ;
        }
        tmp = tmp->next ;
        pos++ ;
    }
    return min_pos ;
}

t_stack_node *max_node(t_stack_node *stack)
{
    t_stack_node *max_node ;

    if (!stack)
        return NULL;
    max_node = stack ;
    while (stack)
    {
        if (max_node->nbr < stack->nbr)
            max_node = stack ;
        stack = stack->next ;
    }
    return max_node ;
}

void move_min_to_top(t_stack_node **stack_a)
{
    int pos ;
    int len ;

    pos = find_min_pos(*stack_a) ;
    len = stack_len(*stack_a) ;
    if (pos <= len / 2)
    {
        while (pos--)
            ft_rotate_sa(stack_a, true) ;
    }
    else 
    {
        pos = len - pos ;
        while (pos--)
            ft_reverse_rotate_sa(stack_a, true) ;
    }
}