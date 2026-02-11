#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stack_node
{
    int nbr ;
    int index ;
    int push_cost ;

    bool cheapest ;
    bool above_median ;

    struct stack_node *target_node ;
    struct stack_node *next ;
    struct stack_node *prev ;
} t_stack_node ;

char	**ft_split(const char *s, char c) ;
void init_stack_a(t_stack_node **a, char **argv) ;
bool    stack_sorted(t_stack_node *stack) ;
bool    stack_sorted(t_stack_node *stack) ;
t_stack_node *find_last_node(t_stack_node *stack) ;
void free_stack(t_stack_node **stack) ;
#endif