/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:39:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 15:39:42 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_non_lis_to_b(t_stack *a, t_stack *b, int *lis, int lis_length)
{
	while (a->size > lis_length)
	{
		if (!is_in_lis(a->top->data, lis, lis_length))
		{
			pb(b, a);
		}
		else
		{
			ra(a);
		}
	}
}
