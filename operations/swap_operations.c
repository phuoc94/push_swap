/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:23 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 17:56:30 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	if (!stack)
		return ;
	ft_putstr_fd("sa\n", 1);
	ft_swap(stack);
}

void	sb(t_stack *stack)
{
	if (!stack)
		return ;
	ft_putstr_fd("sb\n", 1);
	ft_swap(stack);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	if (!stack1 || !stack2)
		return ;
	ft_putstr_fd("ss\n", 1);
	ft_swap(stack1);
	ft_swap(stack2);
}
