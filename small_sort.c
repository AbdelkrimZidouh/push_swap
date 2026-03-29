#include "push_swap.h"

static void sort_three(t_stack_node **a)
{
    t_stack_node *biggest_node ;

    biggest_node = max_node(*a) ;
    if (biggest_node == *a)
        ft_rotate_sa(a, true) ;
    else if ((*a)->next == biggest_node)
        ft_reverse_rotate_sa(a, true) ;
    if ((*a)->nbr > (*a)->next->nbr)
        ft_swap_sa(a, true) ;
}

static void sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
    move_min_to_top(stack_a) ;
    ft_push_to_sb(stack_a, stack_b, true) ;
    sort_three(stack_a) ;
    ft_push_to_sa(stack_a, stack_b, true) ;
}

static void sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
    move_min_to_top(stack_a);
    ft_push_to_sb(stack_a, stack_b, true) ;
    move_min_to_top(stack_a);
    ft_push_to_sb(stack_a, stack_b, true) ;
    sort_three(stack_a);
    // remettre les deux plus petits depuis B
    if ((*stack_b)->nbr < (*stack_b)->next->nbr)
        ft_swap_sb(stack_b, true); 
    ft_push_to_sa(stack_a, stack_b, true) ;
    ft_push_to_sa(stack_a, stack_b, true) ;
}

void small_sort(t_stack_node **a, t_stack_node **b)
{
    int len = stack_len(*a);

    if (len == 2)
        ft_swap_sa(a, true);
    else if (len == 3)
        sort_three(a);
    else if (len == 4)
        sort_four(a, b);
    else if (len == 5)
        sort_five(a, b);
}