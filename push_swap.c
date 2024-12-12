/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:47:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 19:48:37 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
1. Find the smallest number in Stack A.-
2. Move the smallest number found to the top of Stack A.
3. Push that number to Stack B.
4. Repeat steps 1–3 until Stack A is empty.
5. Push everything back to stack A once Stack B has all the numbers from biggest to smallest.
*/

int	find_smallest_index(t_stack *a)
{
	int		index;
	int		smallest;
	int		smallest_index;
	t_frame	*current;

	index = 0;
	smallest_index = 0;
	smallest = a->top->data;
	current = a->top;
	while (current)
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_index = index;
		}
		current = current->next;
		index++;
	}
	return (smallest_index);
}

void	move_to_top(t_stack *a, int index)
{
	if (index <= a->size / 2)
		while (index-- > 0)
			ra(a);
	else
	{
		index = a->size - index;
		while (index-- > 0)
			rra(a);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	smallest_index;

	while (a->size > 0)
	{
		smallest_index = find_smallest_index(a);
		move_to_top(a, smallest_index);
		pb(b, a);
	}
	while (b->size > 0)
		pa(a, b);
}

