/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:15 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 00:23:39 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	if (!stack)
		return ;
	write(1, "ra\n", 3);
	ft_shift_up(stack);
}

void	rb(t_stack *stack)
{
	if (!stack)
		return ;
	write(1, "ra\n", 3);
	ft_shift_up(stack);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	if (!stack1 || !stack2)
		return ;
	write(1, "rr\n", 3);
	ft_shift_up(stack1);
	ft_shift_up(stack2);
}
