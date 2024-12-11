/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:32 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 00:29:27 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	t_frame	*x;
	t_frame	*y;

	x = stack1->top;
	y = stack2->top;
	while (x || y)
	{
		if (x && y)
		{
			printf("a: %d, b: %d \n", x->data, y->data);
			x = x->next;
			y = y->next;
		}
		else if (x)
		{
			printf("a: %d, b: \n", x->data);
			x = x->next;
		}
		else if (y)
		{
			printf("a:  , b: %d\n", y->data);
			y = y->next;
		}
		else
			break ;
	}
	printf("------------------------\n");
}

int	is_stack_sorted(t_stack *stack)
{
	t_frame	*current;

	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
