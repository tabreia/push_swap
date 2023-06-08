/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:03:03 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/05 13:14:39 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_order(t_list **stack)
{
	t_list	*temp_node;
	void	*num;

	temp_node = (*stack)->next;
	num = (*stack)->content;
	while (temp_node != NULL)
	{
		if (temp_node->content < num)
			return (0);
		num = temp_node->content;
		temp_node = temp_node->next;
	}
	return (1);
}

int	check_order(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b))
		return (0);
	if (check_stack_order(stack_a))
		return (1);
	else
		return (0);
}
