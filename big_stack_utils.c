/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:03:23 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/19 13:03:23 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pull_hold(int hold_first, int hold_second, t_list **stack_a, \
															t_list**stack_b)
{
	if (compare_holds(hold_first, hold_second, stack_a) == 1)
	{
		pull_index_to_top(hold_first, stack_a, 1);
		push(stack_a, stack_b, 0);
	}
	else
	{
		pull_index_to_top(hold_second, stack_a, 1);
		push(stack_a, stack_b, 0);
	}
	return (1);
}
