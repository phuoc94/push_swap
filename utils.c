/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:32 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/02 12:22:06 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_line(t_frame *x, t_frame *y)
{
	if (x && y)
		ft_printf("a: %d, b: %d\n", x->data, y->data);
	else if (x)
		ft_printf("a: %d, b: \n", x->data);
	else if (y)
		ft_printf("a:  , b: %d\n", y->data);
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	t_frame	*x;
	t_frame	*y;

	x = stack1->top;
	y = stack2->top;
	while (x || y)
	{
		print_stack_line(x, y);
		if (x)
			x = x->next;
		if (y)
			y = y->next;
	}
	ft_printf("------------------------\n");
}

int	is_stack_sorted(t_stack *stack)
{
	t_frame	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
