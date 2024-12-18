/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:47:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/18 14:23:06 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node_data(t_frame *node)
{
	ft_printf("data: %d\n", node->data);
	ft_printf("current_position: %d\n", node->current_position);
	ft_printf("final_index: %d\n", node->final_index);
	ft_printf("push_price: %d\n", node->push_price);
	ft_printf("above_median: %d\n", node->above_median);
	ft_printf("cheapest: %d\n", node->cheapest);
	ft_printf("target_node->data: %d\n", node->target_node->data);
	ft_printf("---------------------------------\n");
}

void	push_swap(t_stack *a, t_stack *b)
{
	int		*lis;
	int		lis_length;
	t_frame	*smallest;

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
