/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helpper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/16 16:24:15 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//
//
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
