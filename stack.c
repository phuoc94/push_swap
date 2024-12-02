/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:53:04 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/02 21:21:51 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_stack *pop(t_stack **stack)
{
	if((*stack)->head == NULL)
		return (NULL);


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
