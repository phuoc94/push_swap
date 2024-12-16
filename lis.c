/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:38:59 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/16 22:24:13 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*reconstruct_lis(t_lis listype)
{
	int	*lis;
	int	i;
	int last_index;
	int length;

	length = listype.lis_size;
	last_index = listype.max_index;
	lis = malloc(sizeof(int) * length);
	i = length - 1;
	while (last_index >= 0)
	{
		lis[i] = listype.arr[last_index];
		last_index = listype.prev_index[last_index];
		i--;
	}
	return (lis);
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

void init_lis(t_lis listype, int size)
{
	int i;

	if(listype.arr == NULL)
		return;
	listype.lis = malloc(sizeof(int) * size);
	if(listype.lis == NULL)
		return;
	listype.prev_index = malloc(sizeof(int) * size);
	if(listype.prev_index == NULL)
		return;

	i = 0;
	while (i < size)
	{
		listype.lis[i] = 1;
		listype.prev_index[i] = -1;
		i++;
	}
}
void find_lis(t_lis listype)
{
	int i;
	int j;

	i = 1;
	while (i < listype.arr_size)
	{
		j = 0;
		while(j < i)
		{
			if (listype.arr[j] < listype.arr[i] && listype.lis[i] < listype.lis[j] + 1)
			{
				listype.lis[i] = listype.lis[j] + 1;
				listype.prev_index[i] = j;
			}
			j++;
		}
		i++;
	}
}
int	*get_lis(t_stack *stack, int *length)
{
	t_lis listype;
	int 	*reconstructed_lis;

	listype.arr = stack_to_array(stack);
	listype.arr_size = stack->size;
	listype.max_index = get_max_index(listype.lis, stack->size);
	*length = listype.lis[listype.max_index];

	print_arr(listype.lis, listype.lis_size);
	ft_printf("x\n");
	reconstructed_lis = reconstruct_lis(listype);
	ft_printf("xx\n");

	return (reconstructed_lis);
}

void print_arr(int *arr, int size)
{
	int i;
	i = 0;

	while (i < size)
	{
		ft_printf("arr[%d]: %d\n",i ,arr[i]);
		i++;
	}
	ft_printf("------------------------------\n");
}
