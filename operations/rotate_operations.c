/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:15 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 17:56:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack)
{
	if (!stack)
		return ;
	ft_putstr_fd("ra\n", 1);
	ft_shift_up(stack);
}

void	rb(t_stack *stack)
{
	if (!stack)
		return ;
	ft_putstr_fd("rb\n", 1);
	ft_shift_up(stack);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	if (!stack1 || !stack2)
		return ;
	ft_putstr_fd("rr\n", 1);
	ft_shift_up(stack1);
	ft_shift_up(stack2);
}
