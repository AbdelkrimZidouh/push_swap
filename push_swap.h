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

#endif