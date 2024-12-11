/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:10 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/11 22:18:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *stack)
{
	if(!stack)
		return;

	write(1, "rra\n", 4);

	ft_shift_down(stack);
}
void rrb(t_stack *stack)
{
	if(!stack)
		return;

	write(1, "rra\n", 4);

	ft_shift_down(stack);
}
void rrr(t_stack *stack1, t_stack *stack2)
{
	if(!stack1 || !stack2)
		return;

	write(1, "rrr\n", 4);

	ft_shift_down(stack1);
	ft_shift_down(stack2);
}
