/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:15:17 by mnassiri          #+#    #+#             */
/*   Updated: 2026/02/22 14:58:25 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	sa(t_stack_node **a, int print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, int print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
