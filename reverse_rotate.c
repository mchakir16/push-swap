/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:14:47 by mnassiri          #+#    #+#             */
/*   Updated: 2026/02/22 14:52:55 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	prev->next = NULL;
}

void	rra(t_stack_node **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
