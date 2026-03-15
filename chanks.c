#include "push_swap.h"

static int get_chunk_count(int size)
{
    if (size <= 100)
        return (5);
    else
        return (11);
}

static int find_max_pos(t_stack_node *stack_b)
{
    int pos ;
    int max_pos ;
    int max ;
    t_stack_node *tmp ;

    pos = 0 ;
    max_pos = 0 ;
    max = stack_b->nbr ;
    tmp = stack_b ;
    while (tmp)
    {
        if (tmp->nbr > max)
        {
            max = tmp->nbr ;
            max_pos = pos ;
        }
        tmp = tmp->next ;
        pos++ ;
    }
    return max_pos ;
}

static void push_chunks(t_stack_node **a, t_stack_node **b)
{
    int chank_size ;
    int chank_max ;
    int chank_middle ;

    chank_size = stack_len(*a) / get_chunk_count(stack_len(*a)) ;
    chank_max = chank_size ;
    chank_middle = chank_size / 2 ;
    while (*a)
    {
        if ((*a)->index < chank_max)
        {
            ft_push_to_sb(*a, *b, false) ;
            if ((*b)->index < chank_max - chank_middle)
                ft_rotate_sb(*b, false) ;
        }
        else
        {
            ft_rotate_sa(*a, false) ;
        }
        if (stack_len(*b) == chank_max)
            chank_max += chank_size ;
    }
}

static void push_back(t_stack_node **a, t_stack_node **b)
{
    int pos ;
    int len ;

    while (*b)
    {
        pos = find_max_pos(*b);
        len = stack_len(*b) ;
        if (pos <= (len / 2))
        {
            while (pos--)
                ft_rotate_sb(*b, false) ;
        }
        else
        {
            pos = len - pos ;
            while (pos--)
                ft_reverse_rotate_sb(*b, false) ;
        }
        ft_push_to_sa(*a, *b, false) ;
    }
}

void chunk_sort(t_stack_node **a, t_stack_node **b)
{
    push_chunks(a, b);
    push_back(a, b);
}

