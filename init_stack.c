/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negane <negane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:41:02 by mchakir           #+#    #+#             */
/*   Updated: 2026/03/12 23:20:12 by negane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	sum;
	int		sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sign * sum);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	node->index = 0;
	if (!(*stack))
	{
		*stack = node;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
	}
}

void	free_stack(t_stack_node **head)
{
	t_stack_node	*cur;
	t_stack_node	*tmp;

	cur = *head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*head = NULL;
}

t_stack_node	*extract_stack(t_stack_node *st, int count, char **av)
{
	int		i;
	char	**splited_arr;
	char	**buffer;

	i = 0;
	// if (!st || !av || !*av)
	//	return (NULL);
	if (empty_args(count, av))
		return (free(st), NULL);
	while (++i < count)
	{
		splited_arr = ft_split(av[i], ' ');
		buffer = splited_arr;
		while (*splited_arr != NULL)
		{
			if (!valid(*splited_arr) || in_stack(ft_atoi(*splited_arr), &st)
				|| long_num(*splited_arr))
				return (free_split(buffer), free_stack(&st), NULL);
			append_node(&st, ft_atoi(*splited_arr++));
		}
		free_split(buffer);
	}
	return (st);
}
