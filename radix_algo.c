/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:34:04 by mchakir           #+#    #+#             */
/*   Updated: 2026/03/09 04:11:40 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack_node **stack)
{
	t_stack_node	*head;
	int				max;
	int				max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(a);
	size = stack_size(*a);
	while ((size >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (stack_size(*b) != 0)
			pa(a, b, 1);
		i++;
	}
}
