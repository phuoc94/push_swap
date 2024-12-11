#include "push_swap.h"
#include <stdio.h>

void print_stacks(t_stack *stack1, t_stack *stack2)
{
	t_frame *x;
	t_frame *y;

	x = stack1->top;
	y = stack2->top;
	while (x || y)
	{
		if(x && y)
		{
			printf("a: %d, b: %d \n", x->data, y->data);
			x = x->next;
			y = y->next;
		} else if(x)
		{
			printf("a: %d, b: \n", x->data);
			x = x->next;
		} else if(y)
		{
			printf("a:  , b: %d\n", y->data);
			y = y->next;
		}
		else
		{
			break;
		}
	}
	printf("------------------------\n");
}
