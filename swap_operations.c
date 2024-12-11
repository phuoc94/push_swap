#include "push_swap.h"

void sa(t_stack **stack)
{
	if(!*stack)
		return;

	write(1, "sa\n", 3);

	ft_swap(stack);
}

void sb(t_stack **stack)
{
	if(!*stack)
		return;

	write(1, "sb\n", 3);

	ft_swap(stack);
}

void ss(t_stack **stack1 ,t_stack **stack2)
{
	if(!*stack1 && !*stack2)
		return;

	write(1, "ss\n", 3);

	ft_swap(stack1);
	ft_swap(stack2);
}
