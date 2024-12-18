/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/18 17:09:48 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	second_val;
	int	third_val;

	second_val = a->top->next->data;
	third_val = a->top->next->next->data;
	if (a->top->data > second_val && second_val < third_val
		&& a->top->data < third_val)
		sa(a);
	else if (a->top->data > second_val && second_val > third_val)
	{
		sa(a);
		rra(a);
	}
	else if (a->top->data > second_val && second_val < third_val
		&& a->top->data > third_val)
		ra(a);
	else if (a->top->data < second_val && second_val > third_val
		&& a->top->data < third_val)
	{
		sa(a);
		ra(a);
	}
	else if (a->top->data < second_val && second_val > third_val
		&& a->top->data > third_val)
		rra(a);
}

void	move_non_lis_to_b(t_stack *a, t_stack *b, int *lis, int lis_length)
{
	while (a->size > lis_length && a->size > 3)
	{
		if (!is_in_lis(a->top->data, lis, lis_length))
			pb(b, a);
		else
			ra(a);
	}
	if (a->size == 3)
		sort_three(a);
}
