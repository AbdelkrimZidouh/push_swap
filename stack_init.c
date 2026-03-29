/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:41:18 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:22:16 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack_node **a, char **argv)
{
	int				i;
	t_stack_node	*tail;

	i = 0;
	tail = NULL;
	while (argv[i])
	{
		process_arg(a, argv[i], &tail);
		i++;
	}
}
