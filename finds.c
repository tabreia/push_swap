/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:50:18 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/19 11:59:33 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list **stack)
{
	t_list	*temp_node;
	t_list	*node_max;

	temp_node = (*stack)->next;
	node_max = (*stack);
	while (temp_node != NULL)
	{
		if ((int)(long)temp_node->content > (int)(long)node_max->content)
			node_max = temp_node;
		temp_node = temp_node->next;
	}
	return (node_max);
}

t_list	*find_min(t_list **stack)
{
	t_list	*temp_node;
	t_list	*node_min;

	temp_node = (*stack);
	node_min = (*stack);
	while (temp_node != NULL)
	{
		if ((int)(long)temp_node->content < (int)(long)node_min->content)
		{
			node_min = temp_node;
		}
		temp_node = temp_node->next;
	}
	return (node_min);
}

int	find_mid_point(t_list	**stack)
{
	int	size;
	int	mid_point;

	size = ft_lstsize((*stack));
	mid_point = size / 2;
	return (mid_point);
}

int	find_middle_place(void *num, t_list **stack_dest)
{
	t_list	*temp_node;
	int		i;
	int		diff;
	int		temp;
	int		index;

	i = 0;
	index = 0;
	temp = (int)(long) find_max(stack_dest)->content;
	temp_node = (*stack_dest);
	while (temp_node != NULL)
	{
		if ((int)(long)temp_node->content > (int)(long)num)
		{
			diff = (int)(long)temp_node->content - (int)(long)num;
			if (diff < temp)
			{
				temp = diff;
				index = i;
			}
		}
		i++;
		temp_node = temp_node->next;
	}
	return (index);
}

int	find_place(t_list **stack_src, t_list **stack_dest)
{
	int		i;
	int		index;
	void	*num;

	index = 0;
	num = (*stack_src)->content;
	i = check_if_min(num, stack_dest);
	if (i != ft_lstsize((*stack_dest)) + 1)
		return (i);
	i = check_if_max(num, stack_dest);
	if (i != ft_lstsize((*stack_dest)) + 1)
		return (i);
	index = find_middle_place(num, stack_dest);
	return (index);
}
