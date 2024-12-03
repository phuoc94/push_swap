/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:53:04 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/03 18:57:28 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int pop(t_stack **stack)
{
	int r;
	t_frame *tmp;
	if((*stack)->head == NULL)
		return (-1);

	r = (*stack)->head->data;
	tmp = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	(*stack)->size--;
	free(tmp);
	return (r);
}

t_stack *push(t_stack **stack, int data)
{
	t_frame *frame;

	frame = malloc(sizeof(t_frame));
	if(!frame)
		return (NULL);

	frame->data = data;
	frame->next = (*stack)->head;
	(*stack)->head = frame;
	(*stack)->size++;

	return (*stack);
}

t_stack *initialize_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if(!(*stack))
		return (NULL);

	(*stack)->head = NULL;
	(*stack)->size = 0;

	return (*stack);

}
