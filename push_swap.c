/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:37:13 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/12 15:49:34 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	void	*first;
	void	*mid;
	void	*last;

	first = (*stack_a)->content;
	mid = (*stack_a)->next->content;
	last = ft_lstlast((*stack_a))->content;
	if ((first > mid) && (first < last))
		swap(stack_a, 1);
	else if ((first > mid) && (mid > last))
	{
		swap(stack_a, 1);
		r_rotate(stack_a, 1);
	}
	else if ((first > mid) && (mid < last))
		rotate(stack_a, 1);
	else if ((first < mid) && (mid > last) && (first < last))
	{
		swap(stack_a, 1);
		rotate(stack_a, 1);
	}
	else if ((first < mid) && (mid > last))
		r_rotate(stack_a, 1);
	if (check_stack_order(stack_a))
		return ;
}

void	place_top_elem(t_list **stack_a, t_list **stack_b)
{
	int		index;
	t_list	*min;

	while (ft_lstsize((*stack_b)) != 0)
	{
		index = check_if_min((*stack_b)->content, stack_a);
		if (index != ft_lstsize((*stack_a)) + 1)
			push(stack_b, stack_a, 1);
		if (ft_lstsize((*stack_b)) == 0)
			return ;
		index = check_if_max((*stack_b)->content, stack_a);
		if (index != ft_lstsize((*stack_a)) + 1)
		{
			push(stack_b, stack_a, 1);
			rotate(stack_a, 1);
		}
		if (ft_lstsize((*stack_b)) == 0)
			return ;
		index = find_place(stack_b, stack_a);
		pull_index_to_top(index, stack_a, 1);
		push(stack_b, stack_a, 1);
		min = find_min(stack_a);
		index = find_index(min, stack_a);
		pull_index_to_top(index, stack_a, 1);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize((*stack_a)) >= 4)
		push(stack_a, stack_b, 0);
	sort_three(stack_a);
	while (*stack_b)
		place_top_elem(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	check_stack_order(stack_a);
	if (ft_lstsize((*stack_a)) == 1)
		return ;
	if (ft_lstsize((*stack_a)) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a, 1);
	}
	if (ft_lstsize((*stack_a)) == 3)
		sort_three(stack_a);
	else if (ft_lstsize((*stack_a)) <= 5)
		sort_five(stack_a, stack_b);
	else if (ft_lstsize((*stack_a)) > 5)
		big_stack(stack_a, stack_b, ft_lstsize((*stack_a)));
}
