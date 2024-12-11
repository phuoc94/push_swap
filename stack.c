/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:53:04 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/11 22:14:34 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pop(t_stack *stack)
{
	int r;
	t_frame *tmp;
	if(stack->top == NULL)
		return (-1);

	r = stack->top->data;
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	free(tmp);
	return (r);
}

t_stack *push(t_stack *stack, int data)
{
	t_frame *frame;

	frame = malloc(sizeof(t_frame));
	if(!frame)
		return (NULL);

	frame->data = data;
	frame->next = stack->top;
	stack->top = frame;
	stack->size++;

	return (stack);
}

t_stack *initialize_stack(t_stack *stack)
{
	stack = malloc(sizeof(t_stack));
	if(!stack)
		exit(EXIT_FAILURE);

	stack->top = NULL;
	stack->size = 0;

	return (stack);
}
