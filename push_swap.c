/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:46:09 by azidouh           #+#    #+#             */
/*   Updated: 2026/02/11 19:46:11 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack_node *stack)
{
	printf("--- STACK A ---\n");
	if (!stack)
		printf("(empty)\n");
	while (stack)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
	printf("---------------\n");
}

static void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	bool			to_free;

	a = NULL;
	b = NULL;
	to_free = false;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		to_free = true;
		if (argv[1] == NULL)
		{
			write(2, "Error\n", 6);
			free_argv(argv);
			return (1);
		}
	}
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (to_free)
		free_argv(argv);
	print_stack(a);
	free_stack(&a);
	return (0);
}
