/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helpper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:17:49 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 13:53:42 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_frame	*temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp->next = stack->top->next;
	stack->top->next = temp;
	return ;
}

void	ft_push_to(t_stack *des, t_stack *src)
{
	if (!src || !src->top || !des)
		return ;
	push(des, src->top->data);
	pop(src);
	return ;
}

void	ft_shift_down(t_stack *stack)
{
	t_frame	*first;
	t_frame	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	if (!current->next)
		return ;
	first = current;
	while (current->next->next)
		current = current->next;
	current->next->next = first;
	stack->top = current->next;
	current->next = NULL;
}

void	ft_shift_up(t_stack *stack)
{
	t_frame	*first;
	t_frame	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	if (!current->next)
		return ;
	first = current;
	stack->top = current->next;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
}
