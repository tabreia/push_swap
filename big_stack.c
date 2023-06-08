/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:02:06 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/13 19:44:23 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_first(t_list **stack, int chunk_range_min, int chunk_range_max)
{
	int		i;
	t_list	*temp_node;

	i = 0;
	temp_node = (*stack);
	while (temp_node != NULL)
	{
		if (((int)(long)temp_node->content >= chunk_range_min) && ((int)
		(long)temp_node->content <= chunk_range_max))
			return (i);
		temp_node = temp_node->next;
		i++;
	}
	return (ft_lstsize((*stack)) + 1);
}

int	locate_second(t_list **stack, int chunk_range_min, int chunk_range_max)
{
	int		i;
	int		index;
	t_list	*temp_node;

	i = 0;
	temp_node = (*stack);
	while (temp_node != NULL)
	{
		if (((int)(long)temp_node->content >= chunk_range_min) && ((int)
		(long)temp_node->content <= chunk_range_max))
		{
			index = i;
		}
		temp_node = temp_node->next;
		i++;
	}
	return (index);
}

int	pull_chunk(t_list **stack_a, t_list **stack_b, \
		int current_chunk, int chunk_range)
{
	int	current_chunk_range_max;
	int	current_chunk_range_min;
	int	hold_first;
	int	hold_second;

	current_chunk_range_max = ((int)(long) find_min(stack_a)->content
			+ chunk_range) * current_chunk;
	current_chunk_range_min = (int)(long) find_min(stack_a)->content;
	hold_first = locate_first(stack_a, \
	current_chunk_range_min, current_chunk_range_max);
	if (hold_first == ft_lstsize((*stack_a)) + 1)
		return (0);
	hold_second = locate_second(stack_a, \
	current_chunk_range_min, current_chunk_range_max);
	return (pull_hold(hold_first, hold_second, stack_a, stack_b));
}

void	order_stack(t_list **stack_a, t_list **stack_b)
{
	int		index;
	t_list	*max;

	max = find_max(stack_b);
	index = find_index(max, stack_b);
	pull_index_to_top(index, stack_b, 0);
	push(stack_b, stack_a, 1);
}

void	big_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_amount;
	int	i;
	int	k;
	int	chunk_range;
	int	count;

	i = 1;
	k = 0;
	count = ft_lstsize((*stack_a));
	if (size > 100)
		chunk_amount = ft_lstsize((*stack_a)) / 30;
	else
		chunk_amount = ft_lstsize((*stack_a)) / 10;
	if (chunk_amount == 0)
		chunk_amount++;
	chunk_range = ((int)(long)find_max(stack_a)->content / chunk_amount) + 1;
	while (i <= chunk_amount)
	{
		while (k++ < count)
			pull_chunk(stack_a, stack_b, i, chunk_range);
		i++;
	}
	while (ft_lstsize((*stack_b)) != 0)
		order_stack(stack_a, stack_b);
}
