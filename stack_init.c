/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:41:18 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/11 19:41:20 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_error(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !(*stack))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

static void	append_node(t_stack_node **a, t_stack_node **tail, int nbr)
{
	t_stack_node	*new_node;

	if (!a || !tail)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		free_error(a);
	new_node->next = NULL;
	new_node->nbr = nbr;
	new_node->index = -1 ;
	if (!(*a))
	{
		*a = new_node;
		*tail = new_node;
		return ;
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

static bool	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (true);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}

static bool	duplicate_error(t_stack_node *stack, int n)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->nbr == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}

static void	free_splited_args(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int     i;
    int     j;
	long	n;
    char    **args_splited;
	t_stack_node	*tail;

    i = 0;
	tail = NULL;
    while (argv[i])
    {
        args_splited = ft_split(argv[i], ' '); 
        if (!args_splited || !args_splited[0]) 
        {
            free_splited_args(args_splited);
            free_error(a) ;
        }
		j = 0; 
        while (args_splited[j])
        {
            if (syntax_error(args_splited[j])) 
            {
                free_splited_args(args_splited);	
				free_error(a) ;
            }
			n = ft_atol(args_splited[j]);
			if (n > INT_MAX || n < INT_MIN)
			{
				free_splited_args(args_splited);
				free_error(a);
			}
			if (duplicate_error(*a, (int)n))
			{
				free_splited_args(args_splited);
				free_error(a);
			}
			append_node(a, &tail, (int)n);
			j++;
        }
        free_splited_args(args_splited);
        i++;
    }
}
