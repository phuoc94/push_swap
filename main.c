/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/10 23:03:09 by phuocngu         ###   ########.fr       */
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

	ft_push_to(&b, &a);
	ft_push_to(&b, &a);
	ft_swap_both(&a ,&b);
	ft_swap_both(&a ,&b);

	while (x && y)
	{
		printf("a: %d, b: %d \n", x->data, y->data);
		x = x->next;
		y = y->next;
	}

	printf("------------------------\n");
	ft_swap(&a);

	x = a->top;
	y = b->top;

	while (x && y)
	{
		printf("a: %d, b: %d \n", x->data, y->data);
		x = x->next;
		y = y->next;
	}

	exit(EXIT_SUCCESS);

}
