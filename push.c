/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:14:31 by mnassiri          #+#    #+#             */
/*   Updated: 2026/02/22 14:42:45 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
