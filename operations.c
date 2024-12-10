#include "push_swap.h"


void ft_swap(t_stack **stack)
{
	t_frame *temp;

	if(!*stack && !(*stack)->top && !(*stack)->top->next)
		return;

	temp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	temp->next = (*stack)->top->next;
	(*stack)->top->next = temp;
	return;
}

void ft_push_to(t_stack **des, t_stack **src)
{
	t_frame *temp;

	if(!*src && !(*src)->top && !*des)
	{
		return;
	}

	push(des, (*src)->top->data);
	pop(src);
	return;
}

void ft_swap_both(t_stack **stack1 ,t_stack **stack2)
{
	if(!*stack1 && !*stack2)
		return;

	ft_swap(stack1);
	ft_swap(stack2);
}
