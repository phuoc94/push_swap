/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:32:44 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 19:41:40 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack *stack)
{
	int		i;
	int		median;
	t_frame	*current;

	if (stack == NULL || stack->top == NULL)
		return ;
	i = 0;
	median = stack->size / 2;
	current = stack->top;
	while (current)
	{
		current->current_position = i;
		current->above_median = (i <= median);
		current = current->next;
		i++;
	}
}

t_frame	*find_target_node(t_stack *target_stack, t_frame *current_b)
{
	int		best_match;
	t_frame	*current_a;
	t_frame	*best_node;

	best_match = INT_MAX;
	if (target_stack == NULL || current_b == NULL)
		return (NULL);
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

void	set_target_node(t_stack *a, t_stack *b)
{
	t_frame	*current_b;
	t_frame	*target_node;

	target_node = NULL;
	current_b = b->top;
	while (current_b)
	{
		target_node = find_target_node(a, current_b);
		if (!target_node)
			current_b->target_node = find_smallest(a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next;
	}
}

void	set_nodes_data(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
}
