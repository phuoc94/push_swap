/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:10 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 17:55:50 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack)
{
	if (!stack)
		return ;
	ft_putstr_fd("rra\n", 1);
	ft_shift_down(stack);
}

void	rrb(t_stack *stack)
{
	if (!stack)
		return ;
	ft_putstr_fd("rrb\n", 1);
	ft_shift_down(stack);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	if (!stack1 || !stack2)
		return ;
	ft_putstr_fd("rrr\n", 1);
	ft_shift_down(stack1);
	ft_shift_down(stack2);
}
