/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:57:36 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/04 12:26:58 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**nums;

	if (ac < 2)
		return (0);
	if (ac > 2)
		nums = av + 1;
	else
		nums = ft_split(av[1], ' ');
	if (validate_input_chars(nums))
	{
		ft_printf("Error\n");
		if (ac == 2)
			free_arr(nums);
		return (0);
	}
	stack_a = init_stack_a(nums, get_size(nums));
	stack_b = init_stack_b(get_size(nums));
	if (ac == 2)
		free_arr(nums);
	if (check_stack_order(stack_a) == 0)
		push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free(stack_b);
}
