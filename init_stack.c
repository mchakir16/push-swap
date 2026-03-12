// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   init_stack.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mchakir <mchakir@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/02/17 22:09:32 by mchakir           #+#    #+#             */
// /*   Updated: 2026/02/22 14:42:19 by mchakir          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

// int	ft_isdigit(int c)
// {
// 	return (c >= '0' && c <= '9');
// }

// static long	ft_atol(const char *s)
// {
// 	long	result;
// 	int		sign;

// 	result = 0;
// 	sign = 1;
// 	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
// 		|| *s == '\v')
// 		s++;
// 	if (*s == '-' || *s == '+')
// 	{
// 		if (*s == '-')
// 			sign = -1;
// 		s++;
// 	}
// 	while (ft_isdigit(*s))
// 		result = result * 10 + (*s++ - '0');
// 	return (result * sign);
// }
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

// void	init_stack_a(t_stack_node **a, char **argv)
// {
// 	long	n;
// 	int		i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (error_syntax(argv[i]))
// 			free_errors(a);
// 		n = ft_atol(argv[i]);
// 		if (n > INT_MAX || n < INT_MIN)
// 			free_errors(a);
// 		if (error_duplicate(*a, (int)n))
// 			free_errors(a);
// 		append_node(a, (int)n);
// 		i++;
// 	}
// }

void free_stack(t_stack_node **head)
{
	t_stack_node *cur;
	t_stack_node *tmp;

	cur = *head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*head = NULL;
}