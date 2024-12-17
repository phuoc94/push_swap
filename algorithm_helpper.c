/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helpper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:08:11 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 21:28:07 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*find_smallest(t_stack *stack)
{
	int		smallest;
	t_frame	*smallest_node;
	t_frame	*current;

	if (stack == NULL)
		return (NULL);
	smallest = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_node = current;
		}
		current = current->next;
	}
	return (smallest_node);
}

t_frame	*find_target_node(t_stack *target_stack, t_frame *current_b)
{
	int		best_match;
	t_frame	*current_a;
	t_frame	*best_node;

	best_match = INT_MAX;
	if (target_stack == NULL || current_b == NULL)
		return (NULL);
	best_node = NULL;
	current_a = target_stack->top;
	while (current_a)
	{
		if (current_a->data > current_b->data && current_a->data < best_match)
		{
			best_match = current_a->data;
			best_node = current_a;
		}
		current_a = current_a->next;
	}
	return (best_node);
}
