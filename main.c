/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/11 22:19:59 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = initialize_stack(a);
	b = initialize_stack(b);

	while (--argc > 0)
		push(a, atoi(argv[argc]));

	while (a || b)
	{
		if((a->top && a->top->next) && a->top->data > a->top->next->data)
			sa(a);
		else
			pb(b, a);
		if(a->size == 0 || is_stack_sorted(a))
		{
			while (b->size)
				pa(a, b);
			break;
		}
	}

	exit(EXIT_SUCCESS);
}
