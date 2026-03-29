/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:19:32 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:26:15 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	process_arg(t_stack_node **a, char *arg, t_stack_node **tail)
{
	int		j;
	long	n;
	char	**split;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		return (free_splited_args(split), free_error(a));
	j = 0;
	while (split[j])
	{
		if (syntax_error(split[j]))
			return (free_splited_args(split), free_error(a));
		n = ft_atol(split[j]);
		if (n > INT_MAX || n < INT_MIN || duplicate_error(*a, (int)n))
			return (free_splited_args(split), free_error(a));
		append_node(a, tail, (int)n);
		j++;
	}
	free_splited_args(split);
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
	new_node->index = -1;
	if (!(*a))
	{
		*a = new_node;
		*tail = new_node;
		return ;
	}
	(*tail)->next = new_node;
	*tail = new_node;
}
