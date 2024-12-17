/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:32:44 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 20:41:12 by phuocngu         ###   ########.fr       */
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

void	set_price(t_stack *a, t_stack *b)
{
	t_frame	*current_b;
	int		len_a;
	int		len_b;

	current_b = b->top;
	len_a = a->size;
	len_b = b->size;
	while (current_b)
	{
		current_b->push_price = current_b->current_position;
		if (!(current_b->above_median))
			current_b->push_price = len_b - (current_b->current_position);
		if (current_b->target_node->above_median)
			current_b->push_price += current_b->target_node->current_position;
		else
			current_b->push_price += len_a
				- (current_b->target_node->current_position);
		current_b = current_b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	best_match_value;
	t_frame	*best_match_node;
	t_frame	*current;

	current = stack->top;
	if (NULL == stack)
		return ;
	best_match_value = INT_MAX;
	while (current)
	{
		if (current->push_price < best_match_value)
		{
			best_match_value = current->push_price;
			best_match_node = current;
		}
		current = current->next;
	}
	best_match_node->cheapest = true;
}

void	set_nodes_data(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
