/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:23:55 by mchakir           #+#    #+#             */
/*   Updated: 2026/03/09 23:58:55 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>  //To define MIN and MAX macros
# include <stdbool.h> //To use bool flags, e.g, to print or not to print
# include <stddef.h>  //For NULL
# include <stdlib.h>  //For malloc and free
# include <unistd.h>  //For write

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

// errors_handle.c
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_errors(t_stack_node **a);
void			free_stack(t_stack_node **stack);

// init_stack.c
void			init_stack_a(t_stack_node **a, char **argv);
int				ft_isdigit(int c);

// stack_utils.c
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*stack_last(t_stack_node *stack);

// radix_algo.c
void			radix_sort(t_stack_node **a, t_stack_node **b);
int				get_max_index(t_stack_node *stack);
int				stack_size(t_stack_node *stack);

// split.c
//char			**ft_split(char *str, char separator);

// main.c
int				main(int argc, char **argv);
void			sorting(t_stack_node **a, t_stack_node **b);

// push
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **a, t_stack_node **b, int print);

// reverse rotate
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);

// rotate
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);

// simple sort
void			sort_3(t_stack_node **stack_a);
void			sort_5(t_stack_node **stack_a, t_stack_node **stack_b);
void			simple_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_3(t_stack_node **stack_a);
void			sort_5(t_stack_node **stack_a, t_stack_node **stack_b);
void			simple_sort(t_stack_node **stack_a, t_stack_node **stack_b);

// swap
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node **b, int print);

void	free_split(char **args);
char	**ft_split(const char *str, char sep);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif