/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <azidouh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:53:35 by azidouh           #+#    #+#             */
/*   Updated: 2026/03/29 14:25:39 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_node
{
	int					nbr;
	int					index;

	struct stack_node	*next;
}						t_stack_node;

char					**ft_split(const char *s, char c);
void					init_stack_a(t_stack_node **a, char **argv);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *stack);
void					free_stack(t_stack_node **stack);
t_stack_node			*min_node(t_stack_node *stack);
t_stack_node			*max_node(t_stack_node *stack);
void					move_min_to_top(t_stack_node **stack_a);
void					assign_index(t_stack_node *stack);
int						stack_len(t_stack_node *stack);

int						ft_isdigit(int c);
long					ft_atol(const char *nptr);

void					ft_push_to_sa(t_stack_node **stack_a,
							t_stack_node **stack_b, bool print);
void					ft_push_to_sb(t_stack_node **stack_a,
							t_stack_node **stack_b, bool print);

void					ft_rotate_sa(t_stack_node **stack_a, bool print);
void					ft_rotate_sb(t_stack_node **stack_b, bool print);
void					ft_rotate_ss(t_stack_node **stack_a,
							t_stack_node **stack_b, bool print);

void					ft_reverse_rotate_sa(t_stack_node **stack_a,
							bool print);
void					ft_reverse_rotate_sb(t_stack_node **stack_b,
							bool print);
void					ft_reverse_rotate_ss(t_stack_node **stack_a,
							t_stack_node **stack_b, bool print);

void					ft_swap_sa(t_stack_node **stack_a, bool print);
void					ft_swap_sb(t_stack_node **stack_b, bool print);
void					ft_swap_ss(t_stack_node **stack_a,
							t_stack_node **stack_b, bool print);

void					small_sort(t_stack_node **a, t_stack_node **b);

void					chunk_sort(t_stack_node **a, t_stack_node **b);
void					push_chunks(t_stack_node **a, t_stack_node **b);
void					push_back(t_stack_node **a, t_stack_node **b);
int						get_chunk_size(int size);
int						find_target_pos(t_stack_node *stack, int max_index);
int						find_max_pos(t_stack_node *stack);
void					move_to_top_a(t_stack_node **a, int pos);
void					move_to_top_b(t_stack_node **b, int pos);

void					free_error(t_stack_node **stack);
bool					syntax_error(char *str);
bool					duplicate_error(t_stack_node *stack, int n);
void					process_arg(t_stack_node **a, char *arg,
							t_stack_node **tail);
void					append_node(t_stack_node **a, t_stack_node **tail,
							int nbr);

#endif