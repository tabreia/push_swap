/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:09:08 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/03 18:19:43 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**init_stack_b(int size)
{
	t_list	**stack_b;

	stack_b = malloc(sizeof(t_list *) * size);
	(*stack_b) = 0;
	return (stack_b);
}

t_list	**init_stack_a(char **nums, int size)
{
	t_list	**stack_a;
	int		i;

	i = 0;
	stack_a = malloc(sizeof(t_list *) * size);
	while (nums[i])
	{
		if (i == 0)
			(*stack_a) = ft_lstnew((void *)(long)ft_atoi(nums[i]));
		else
			ft_lstadd_back(stack_a, ft_lstnew((void *)(long)ft_atoi(nums[i])));
		i++;
	}
	return (stack_a);
}
