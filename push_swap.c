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


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int len ;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	init_stack_a(&a, argv + 1);
	assign_index(a);
	len = stack_len(a) ;
	if (!stack_sorted(a))
	{
		if (len <= 5)
			small_sort(&a, &b);
		else
			chunk_sort(&a, &b);
	}
	print_stack(a);
	free_stack(&a);
	return (0);
}

