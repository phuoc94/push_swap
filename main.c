/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/03 21:09:20 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int i;

	a = initialize_stack(&a);
	if (!a)
		exit(EXIT_FAILURE);

	b = initialize_stack(&a);
	if (!b)
		exit(EXIT_FAILURE);


	i = 1;
	while (i < argc)
	{
		push(&a, atoi(argv[i]));
		i++;
	}

	t_frame *x = a->head;

	while (x && x->next)
	{
		printf("x: %d\n", x->data);
		x = x->next;
	}

	exit(EXIT_SUCCESS);

}
