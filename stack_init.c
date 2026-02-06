#include "push_swap.h"
#include "libft/libft.h"

void append_node(t_stack_node **a, int nbr)
{
    t_stack_node *new_node ;
    t_stack_node *last_node ;

    if (!a)
        return ;
    new_node = malloc(sizeof(t_stack_node)) ;
    if (!new_node)
        free_error(a) ;
    new_node->next = NULL ;
    new_node->nbr = nbr ;
    if (!(*a))
    {
        *a = new_node;
        new_node->prev = NULL;
        return;
    }
    last_node = find_last_node(*a);
    last_node->next = new_node;
    new_node->prev = last_node;


}

long	ft_atol(const char *nptr)
{
	size_t	i;
	int		signe;
	long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;

	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;

	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (nbr > (LONG_MAX - (nptr[i] - '0')) / 10)
			return (signe == 1 ? LONG_MAX : LONG_MIN);
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * signe);
}

bool synthax_error(char *str)
{
    int i ;

    i = 0 ;

    if (str[i] == '+' || str[i] == '-' )
        i++ ;

    if (!str[i]) 
        return (true);

    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return true ;
        i++ ;
    }   

    return  false ;
}

bool duplicate_error(t_stack_node *stack, int n){
    if (!stack)
        return false ;
    while (stack)
    {
        if (stack->nbr == n)
            return true; 
        stack = stack->next;
    }
    return false ;
}

void free_error(t_stack_node **stack)
{
    t_stack_node *tmp ;
    t_stack_node *current ;

    if (!stack || !(*stack))
    {
        write(2, "Error\n", 6) ;
        exit(1) ;
    }

    current = *stack ;
    while (current)
    {
        tmp = current->next ;
        free(current) ;
        current = tmp ;
    }
    *stack = NULL ;
    write(2, "Error\n", 6) ;
    exit(1) ;
}
void init_stack_a(t_stack_node **a, char **argv)
{
    long n;
    int i ;

    i = 0 ;
    while (argv[i])
    {
        if (synthax_error(argv[i]))
            free_error(a) ;
        n = ft_atol(argv[i]) ;
        if (n > INT_MAX || n < INT_MIN)
            free_error(a) ;
        if (duplicate_error(*a, (int)n))
            free_error(a) ;
        append_node(a, (int)n) ;
        i++ ;
    }
}