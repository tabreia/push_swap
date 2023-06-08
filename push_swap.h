/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:16:58 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/05 13:14:16 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

int			count_steps(int i, int mid, int list_size);
int			validate_input_chars(char **input);
int			get_size(char **input);
int			check_order(t_list **stack_a, t_list **stack_b);
int			check_stack_order(t_list **stack);
int			find_place(t_list **stack_src, t_list **stack_dest);
int			compare_holds(int hold_first, int hold_second, t_list **stack);
int			find_index(t_list *node, t_list **stack);
int			check_if_min(void *num, t_list **stack_dest);
int			check_if_max(void *num, t_list **stack_dest);
int			find_mid_point(t_list	**stack);
int			pull_hold(int hold_first, int hold_second, \
	t_list **stack_a, t_list**stack_b);

void		free_arr(char **nums);
void		free_stack(t_list **stack);
void		push(t_list **stack_src, t_list **stack_dest, int id);
void		swap(t_list **stack, int id);
void		rotate(t_list **stack, int id);
void		r_rotate(t_list **stack, int id);
void		push_swap(t_list **stack_a, t_list **stack_b);
void		big_stack(t_list **stack_a, t_list **stack_b, int size);
void		run_dev_ops(t_list **stack_0, t_list **stack_1);
void		pull_index_to_top(int index, t_list **stack, int id);
void		order_stack(t_list **stack_a, t_list **stack_b);

t_list		**init_stack_b(int size);
t_list		*find_min(t_list **stack);
t_list		*find_max(t_list **stack);

long int	ft_atol(const char *nptr);

t_list		**init_stack_a(char **nums, int size);

#endif