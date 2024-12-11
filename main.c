/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/11 20:36:19 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
//#include "operatoins.c"
//#include "stack.c"

int main(void)
{
	int argc = 5;
	char *argv[5];
	argv[0] = "asddadsasdasd";
	argv[1] = "2";
	argv[2] = "1";
	argv[3] = "3";
	argv[4] = "4";


	argv[1] = "2";
	argv[2] = "1";
	argv[3] = "3";
	argv[4] = "4";


	t_stack *a;
	t_stack *b;
	int i;

	a = initialize_stack(&a);
	if (!a)
		exit(EXIT_FAILURE);

	b = initialize_stack(&b);
	if (!b)
		exit(EXIT_FAILURE);


	i = argc - 1;
	while (i > 0)
	{
		push(&a, atoi(argv[i]));
		i--;
	}

	t_frame *x;
	t_frame *y;

	x = a->top;
	y = b->top;

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
	ft_shift_down(a);

	x = a->top;
	y = b->top;

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

	exit(EXIT_SUCCESS);

}
