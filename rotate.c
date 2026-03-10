/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:14:52 by mnassiri          #+#    #+#             */
/*   Updated: 2026/02/22 14:53:25 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = stack_last(*stack);
	tail->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack_node **a, int print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, int print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
