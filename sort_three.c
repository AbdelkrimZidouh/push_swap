#include "push_swap.h"

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
void sort_three(t_stack_node **a)
{
    t_stack_node *biggest_node ;

    biggest_node = max_node(*a) ;
    if (biggest_node == *a)
        ra(a) ;
    else if ((*a)->next == biggest_node)
        rra(a) ;
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a) ;
}