/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negane <negane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:46:29 by amerkht           #+#    #+#             */
/*   Updated: 2026/03/12 23:17:51 by negane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	some_digit(char *s)
{
	while (*s)
	{
		if (*s >= 48 && *s <= 57)
			return (1);
		s++;
	}
	return (0);
}

int	valid(char *s)
{
	char	*bf;

	bf = s;
	if (*bf == '-' || *bf == '+')
		bf++;
	if (*bf == '\0')
		return (0);
	while (*bf)
	{
		if (!(*bf >= 48 && *bf <= 57))
			return (0);
		bf++;
	}
	if (!some_digit(s))
		return (0);
	return (1);
}

int	long_num(char *s)
{
	if (ft_atoi(s) > 2147483647 || ft_atoi(s) < -2147483648)
		return (1);
	return (0);
}

int	empty_args(int count, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = 0;
		if (av[i][j] == '\0')
			return (1);
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				break ;
			j++;
		}
		if (av[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	in_stack(int a, t_stack_node **st)
{
	t_stack_node	*cur;

	cur = *st;
	while (cur)
	{
		if (cur->value == a)
		{
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}
