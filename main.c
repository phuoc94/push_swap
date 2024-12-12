/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 17:41:56 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char **argv2;
	int i;


	a = NULL;
	b = NULL;
	i = 0;
	if(argc < 2)
		return (1);

	a = initialize_stack(a);
	b = initialize_stack(b);
	if(argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		while (argv2[i])
			i++;
		i--;
		while (i >= 0)
			push(a, ft_atoi(argv2[i--]));
	}
	else
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
