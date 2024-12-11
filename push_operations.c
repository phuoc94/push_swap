#include "push_swap.h"

void pa(t_stack **des, t_stack **src)
{
	if(!*src && !(*src)->top && !*des)
		return;

	write(1, "pa\n", 3);

	ft_push_to(des, src);
}
void pb(t_stack **des, t_stack **src)
{
	if(!*src && !(*src)->top && !*des)
		return;

	write(1, "pb\n", 3);

	ft_push_to(des, src);
}

