/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:42:50 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/03 16:32:32 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_steps(int i, int mid, int list_size)
{
	int	steps;

	steps = 0;
	if (i > mid)
	{
		while (i <= list_size)
		{
			i++;
			steps++;
		}
	}
	else if (i <= mid)
	{
		while (i > 0)
		{
			i--;
			steps++;
		}
	}
	return (steps);
}

void	pull_index_to_top(int index, t_list **stack, int id)
{
	int	mid;
	int	list_size;

	list_size = ft_lstsize((*stack));
	mid = ft_lstsize((*stack)) / 2;
	if (index <= mid)
	{
		while (index > 0)
		{
			rotate(stack, id);
			index--;
		}
	}
	else
	{
		while (index != list_size)
		{
			r_rotate(stack, id);
			index++;
		}
	}
}

int	compare_holds(int hold_first, int hold_second, t_list **stack)
{
	int	steps_first;
	int	steps_second;
	int	mid;

	mid = ft_lstsize((*stack)) / 2;
	steps_first = count_steps(hold_first, mid, ft_lstsize((*stack)));
	steps_second = count_steps(hold_second, mid, ft_lstsize((*stack)));
	if (steps_first < steps_second)
		return (1);
	else
		return (0);
}

int	find_index(t_list *node, t_list **stack)
{
	int		i;
	t_list	*temp_node;

	i = 0;
	temp_node = (*stack);
	while (temp_node != node)
	{
		i++;
		temp_node = temp_node->next;
	}
	return (i);
}

long int	ft_atol(const char *nptr)
{
	long int	i;
	long int	n;
	long int	signal;

	i = 0;
	n = 0;
	signal = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		signal *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = nptr[i] - 48 + (n * 10);
		i++;
	}
	return (n * signal);
}
