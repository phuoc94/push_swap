/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:38:59 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 17:41:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*reconstruct_lis(t_lis *listype)
{
	int	*lis;
	int	i;
	int	last_index;
	int	length;

	length = (*listype).lis[(*listype).max_index];
	last_index = (*listype).max_index;
	lis = malloc(sizeof(int) * length);
	if (!lis)
		return (NULL);
	i = length - 1;
	while (i >= 0)
	{
		lis[i] = (*listype).arr[last_index];
		last_index = (*listype).prev_index[last_index];
		i--;
	}
	return (lis);
}

int	init_lis(t_lis *listype)
{
	int	i;

	if ((*listype).arr == NULL)
		return (0);
	(*listype).lis = malloc(sizeof(int) * (*listype).arr_size);
	if ((*listype).lis == NULL)
		return (0);
	(*listype).prev_index = malloc(sizeof(int) * (*listype).arr_size);
	if ((*listype).prev_index == NULL)
		return (0);
	i = 0;
	while (i < (*listype).arr_size)
	{
		(*listype).lis[i] = 1;
		(*listype).prev_index[i] = -1;
		i++;
	}
	return (1);
}

void	find_lis(t_lis *listype)
{
	int	i;
	int	j;

	i = 1;
	while (i < (*listype).arr_size)
	{
		j = 0;
		while (j < i)
		{
			if ((*listype).arr[j] < (*listype).arr[i]
				&& (*listype).lis[i] < (*listype).lis[j] + 1)
			{
				(*listype).lis[i] = (*listype).lis[j] + 1;
				(*listype).prev_index[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	free_lis(t_lis *listype)
{
	free((*listype).arr);
	(*listype).arr = NULL;
	free((*listype).lis);
	(*listype).lis = NULL;
	free((*listype).prev_index);
	(*listype).prev_index = NULL;
	listype = NULL;
}

int	*get_lis(t_stack *stack, int *length)
{
	t_lis	listype;
	int		*reconstructed_lis;
	int		status;

	listype.arr = stack_to_array(stack);
	listype.arr_size = stack->size;
	status = init_lis(&listype);
	if (status == 0)
		return (NULL);
	find_lis(&listype);
	listype.max_index = get_max_index(listype.lis, stack->size);
	*length = listype.lis[listype.max_index];
	reconstructed_lis = reconstruct_lis(&listype);
	free_lis(&listype);
	return (reconstructed_lis);
}
