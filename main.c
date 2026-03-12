/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:41:02 by mchakir           #+#    #+#             */
/*   Updated: 2026/03/12 02:59:41 by mchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static void	index_stack(t_stack_node *stack_a)
{
	t_stack_node	*ptr;
	t_stack_node	*current;

	ptr = stack_a;
	while (ptr)
	{
		ptr->index = 0;
		current = stack_a;
		while (current)
		{
			if (ptr->value > current->value)
				ptr->index++;
			current = current->next;
		}
		ptr = ptr->next;
	}
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sorting(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) <= 5)
		simple_sort(a, b);
	else
		radix_sort(a, b);
}


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int 	i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if ((argc == 2 && !argv[1][0]))
		return (write(2, "Error\n", 6), 0);
	// else if (argc == 2)
	// 	argv = ft_split(argv[1], ' ');
	// if (!argv)
		// return (write(2, "Error\n", 6), 0);
	// ft_split(argv[i], ' ')[0]
	a = extract_stack(a, argc,  argv);
	if (!a)
		return (write(2, "Error\n", 6), 0);
	// init_stack_a(&a, argv + 1);
	index_stack(a);
	if (!stack_sorted(a))
		sorting(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
