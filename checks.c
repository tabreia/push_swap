/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:40:10 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/19 12:40:27 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_max(void *num, t_list **stack_dest)
{
	t_list	*temp_node;
	int		i;

	i = 0;
	temp_node = (*stack_dest);
	if ((int)(long)num > (int)(long)find_max(stack_dest)->content)
	{
		while (temp_node != NULL)
		{
			if ((int)(long)temp_node == (int)(long)find_min(stack_dest))
				return (i);
			i++;
			temp_node = temp_node->next;
		}
	}
	return (ft_lstsize((*stack_dest)) + 1);
}

int	check_if_min(void *num, t_list **stack_dest)
{
	t_list	*temp_node;
	int		i;

	i = 0;
	temp_node = (*stack_dest);
	if ((int)(long)num < (int)(long)find_min(stack_dest)->content)
	{
		while (temp_node != NULL)
		{
			if ((int)(long)temp_node == (int)(long)find_max(stack_dest))
				return (i + 1);
			i++;
			temp_node = temp_node->next;
		}
	}
	return (ft_lstsize((*stack_dest)) + 1);
}
