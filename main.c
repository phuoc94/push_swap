/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 16:01:57 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;


	a = NULL;
	b = NULL;
	if(argc < 2)
		return (1);

	a = initialize_stack(a);
	b = initialize_stack(b);
	while (--argc > 0)
		push(a, ft_atoi(argv[argc]));
	push_swap(a, b);
	exit(EXIT_SUCCESS);
}

void	push_swap(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if ((a->top && a->top->next) && a->top->data > a->top->next->data)
			sa(a);
		else
			pb(b, a);
		if (a->size == 0 || is_stack_sorted(a))
		{
			while (b->size)
				pa(a, b);
			break ;
		}
	}
}
