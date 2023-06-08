/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:39:33 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/08 18:11:46 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_list **stack, int id)
{
	t_list	*temp_first;
	t_list	*temp_last;
	t_list	*temp_node;
	char	id_c;

	if (id == 1)
		id_c = 'a';
	else
		id_c = 'b';
	temp_node = (*stack);
	temp_first = temp_node;
	temp_last = ft_lstlast((*stack));
	while (temp_node->next != temp_last)
		temp_node = temp_node->next;
	temp_node->next = 0;
	ft_lstadd_front(stack, ft_lstnew(temp_last->content));
	(*stack)->next = temp_first;
	free(temp_last);
	ft_printf("rr%c\n", id_c);
}

void	rotate(t_list **stack, int id)
{
	t_list	*temp_first;
	t_list	*temp_second;
	char	id_c;

	if (id == 1)
		id_c = 'a';
	else
		id_c = 'b';
	if (ft_lstsize(*stack) < 2)
		return ;
	temp_second = (*stack)->next;
	temp_first = (*stack);
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	(*stack) = temp_second;
	free(temp_first);
	ft_printf("r%c\n", id_c);
}

void	swap(t_list **stack, int id)
{
	void	*temp;
	char	id_c;

	if (id == 1)
		id_c = 'a';
	else
		id_c = 'b';
	if (ft_lstsize(*stack) <= 1)
		return ;
	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	ft_printf("s%c\n", id_c);
}

void	push(t_list **stack_src, t_list **stack_dest, int id)
{
	t_list	*temp;
	char	id_c;

	if (id == 1)
		id_c = 'a';
	else
		id_c = 'b';
	if (!(*stack_src))
		return ;
	temp = (*stack_src)->next;
	ft_lstadd_front(stack_dest, (*stack_src));
	(*stack_src) = temp;
	ft_printf("p%c\n", id_c);
}
