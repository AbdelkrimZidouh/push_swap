#include "push_swap.h"

static int get_chunk_size(int size)
{
    if (size <= 100)
        return (15);
    return (30);
}

static int find_target_pos(t_stack_node *stack, int max_index)
{
    int pos;

    pos = 0;
    while (stack)
    {
        if (stack->index <= max_index)
            return (pos);
        stack = stack->next;
        pos++;
    }
    return (-1);
}

static int find_max_pos(t_stack_node *stack)
{
    int pos;
    int max_pos;
    int max_index;

    pos = 0;
    max_pos = 0;
    max_index = stack->index;
    while (stack)
    {
        if (stack->index > max_index)
        {
            max_index = stack->index;
            max_pos = pos;
        }
        stack = stack->next;
        pos++;
    }
    return (max_pos);
}

static void move_to_top_a(t_stack_node **a, int pos)
{
    int len;
    int steps;

    len = stack_len(*a);
    if (pos <= len / 2)
    {
        while (pos-- > 0)
            ft_rotate_sa(a, true);
    }
    else
    {
        steps = len - pos;
        while (steps-- > 0)
            ft_reverse_rotate_sa(a, true);
    }
}

static void move_to_top_b(t_stack_node **b, int pos)
{
    int len;
    int steps;

    len = stack_len(*b);
    if (pos <= len / 2)
    {
        while (pos-- > 0)
            ft_rotate_sb(b, true);
    }
    else
    {
        steps = len - pos;
        while (steps-- > 0)
            ft_reverse_rotate_sb(b, true);
    }
}

static void push_chunks(t_stack_node **a, t_stack_node **b)
{
    int pushed;
    int chunk_size;
    int target_pos;

    pushed = 0;
    chunk_size = get_chunk_size(stack_len(*a));
    while (*a)
    {
        if ((*a)->index <= pushed)
        {
            ft_push_to_sb(a, b, true);
            ft_rotate_sb(b, true);
            pushed++;
        }
        else if ((*a)->index <= pushed + chunk_size)
        {
            ft_push_to_sb(a, b, true);
            pushed++;
        }
        else
        {
            target_pos = find_target_pos(*a, pushed + chunk_size);
            if (target_pos >= 0)
                move_to_top_a(a, target_pos);
        }
    }
}

static void push_back(t_stack_node **a, t_stack_node **b)
{
    int pos;

    while (*b)
    {
        pos = find_max_pos(*b);
        move_to_top_b(b, pos);
        ft_push_to_sa(a, b, true);
    }
}

void chunk_sort(t_stack_node **a, t_stack_node **b)
{
    push_chunks(a, b);
    push_back(a, b);
}

