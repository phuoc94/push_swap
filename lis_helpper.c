/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 15:36:59 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int		*arr;
	int		i;
	t_frame	*current;

	if (!stack || !(stack->top))
		return (NULL);
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i] = current->data;
		current = current->next;
		i++;
	}
	return (arr);
}

int	get_max_index(int *arr, int size)
{
	int	i;
	int	max;
	int	max_index;

	i = 0;
	max = arr[0];
	max_index = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	is_in_lis(int data, int *lis, int lis_length)
{
	int	i;

	i = 0;
	while (i < lis_length)
	{
		if (data == lis[i])
			return (1);
		i++;
	}
	return (0);
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
	ft_printf("------------------------------\n");
}
