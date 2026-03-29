/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:21:35 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:22:09 by azidouh          ###   ########.fr       */
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
