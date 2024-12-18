/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:47:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/18 23:07:52 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int		*lis;
	int		lis_length;
	t_frame	*smallest;

	if(is_stack_sorted(a))
		return;
	lis = get_lis(a, &lis_length);
	move_non_lis_to_b(a, b, lis, lis_length);
	free(lis);
	while (b->top)
	{
		set_nodes_data(a, b);
		push_cheapest(a, b);
	}
	set_current_position(a);
	smallest = find_smallest(a);
	if (smallest->above_median)
		while (a->top != smallest)
			ra(a);
	else
		while (a->top != smallest)
			rra(a);
}
