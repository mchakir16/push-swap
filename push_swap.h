/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negane <negane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:23:55 by mchakir           #+#    #+#             */
/*   Updated: 2026/03/12 23:12:15 by negane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>  //To define MIN and MAX macros
# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <stddef.h>  //For NULL
# include <stdio.h>
# include <stdlib.h> //For malloc and free
# include <unistd.h> //For write

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}						t_stack_node;

// errors_handle.c
int						some_digit(char *s);
int						valid(char *s);
int						long_num(char *s);
int						empty_args(int count, char **av);
int						in_stack(int a, t_stack_node **st);

// init_stack.c
long					ft_atoi(char *str);
void					append_node(t_stack_node **stack, int n);
void					free_stack(t_stack_node **head);
t_stack_node			*extract_stack(t_stack_node *st, int count, char **av);

// main.c
int						main(int argc, char **argv);
void					sorting(t_stack_node **a, t_stack_node **b);
bool					stack_sorted(t_stack_node *stack);
int						stack_size(t_stack_node *stack);

// push
void					pa(t_stack_node **a, t_stack_node **b, int print);
void					pb(t_stack_node **a, t_stack_node **b, int print);

// radix_algo.c
void					radix_sort(t_stack_node **a, t_stack_node **b);

// reverse rotate
void					rra(t_stack_node **a, int print);
void					rrb(t_stack_node **b, int print);
void					rrr(t_stack_node **a, t_stack_node **b, int print);

// rotate
void					ra(t_stack_node **a, int print);
void					rb(t_stack_node **b, int print);
void					rr(t_stack_node **a, t_stack_node **b, int print);

// simple sort
void					simple_sort(t_stack_node **stack_a,
							t_stack_node **stack_b);
void					sort_3(t_stack_node **stack_a);
void					sort_5(t_stack_node **stack_a, t_stack_node **stack_b);

// split.c
char					**ft_split(const char *str, char sep);

// split_utils.c
size_t					ft_strlen(const char *s);
void					free_split(char **args);

// stack_utils.c
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*stack_last(t_stack_node *stack);
int						stack_len(t_stack_node *stack);

// swap
void					sa(t_stack_node **a, int print);
void					sb(t_stack_node **b, int print);
void					ss(t_stack_node **a, t_stack_node **b, int print);

#endif