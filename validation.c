/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabreia- <tabreia-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:56:26 by tabreia-          #+#    #+#             */
/*   Updated: 2023/04/12 16:00:18 by tabreia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limits(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_atol(input[i]) > INT_MAX)
			return (1);
		if (ft_atol(input[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char *input, char *checked)
{
	int	len;

	len = 0;
	if (ft_strlen(input) >= ft_strlen(checked))
		len = ft_strlen(input);
	else
		len = ft_strlen(checked);
	return (len);
}

int	check_dups(char **input, int size)
{
	char	**checked;
	int		i;
	int		k;

	checked = malloc(sizeof(int *) * size);
	if (!checked)
		return (1);
	checked[0] = input[0];
	i = 0;
	while (input[++i])
	{
		k = -1;
		while (++k < i)
		{
			if (!(ft_strncmp(input[i], checked[k], \
			check_len(input[i], checked[k]))))
			{
				free(checked);
				return (1);
			}
		}
		checked[k] = input[i];
	}
	free (checked);
	return (0);
}

int	check_non_numbers(char **input)
{
	int	i;
	int	k;

	i = 0;
	while (input[i])
	{
		k = 0;
		while (input[i][k])
		{
			if ((input[i][k] > '9' || input[i][k] < '0') && input [i][k] != '-')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	validate_input_chars(char **input)
{
	int	size;

	size = get_size(input);
	if (size == 0)
		return (1);
	if (check_non_numbers(input))
		return (1);
	if (check_dups(input, size))
		return (1);
	if (check_limits(input))
		return (1);
	return (0);
}
