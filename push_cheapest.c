/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:56:15 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 22:52:05 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*find_cheapest_node(t_stack *stack)
{
	t_frame	*current;

	if (stack == NULL)
		return (NULL);
	current = stack->top;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (current);
}

void	rotate_both_till_cheapest(t_stack *a, t_stack *b,
		t_frame *cheapest_node)
{
	while (a->top != cheapest_node->target_node && b->top != cheapest_node)
		rr(a, b);
	while (a->top != cheapest_node->target_node)
		ra(a);
	while (b->top != cheapest_node)
		rb(b);
	set_current_position(a);
	set_current_position(b);
}

void	reverse_rotate_both_till_cheapest(t_stack *a, t_stack *b, t_frame *cheapest_node)
{
	while (a->top != cheapest_node->target_node
		&& b->top != cheapest_node)
	{
		rrr(a, b);
	}
	set_current_position(a);
	set_current_position(b);
}

void rotate_to_target(t_stack *stack, t_frame *target)
{
	t_frame	*current;

	current = stack->top;
	while (current != target)
	{
		if (target->above_median)
			rb(stack);
		else
			rrb(stack);
		current = stack->top;
	}
}
void	push_cheapest(t_stack *a, t_stack *b)
{
	t_frame	*cheapest_node;
	cheapest_node = find_cheapest_node(b);
	if(!cheapest_node)
		return;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_till_cheapest(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both_till_cheapest(a, b, cheapest_node);
	rotate_to_target(a, cheapest_node->target_node);
	rotate_to_target(b, cheapest_node);
	pa(a, b);
}
