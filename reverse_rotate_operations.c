#include "push_swap.h"

void rra(t_stack **stack)
{
	if(!*stack)
		return;

	write(1, "rra\n", 3);

	ft_shift_down(*stack);
}
void rrb(t_stack **stack)
{
	if(!*stack)
		return;

	write(1, "rra\n", 3);

	ft_shift_down(*stack);
}
void rrr(t_stack **stack1, t_stack **stack2)
{
	if(!*stack1 || !*stack2)
		return;

	write(1, "rrr\n", 3);

	ft_shift_down(*stack1);
	ft_shift_down(*stack2);
}
