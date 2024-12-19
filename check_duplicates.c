/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:19:41 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/19 16:02:41 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./hash_table/hash_table.h"

void	check_duplicates(t_stack *stack, t_stack *stack2)
{
	t_hash_table	*hash_table;
	t_frame			*current;

	hash_table = create_hash_table(stack->size);
	current = stack->top;
	while (current)
	{
		if (!insert_to_hash_table(hash_table, current->data))
		{
			print_error();
			free_hash_table(&hash_table);
			free_error(&stack, &stack2);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	free_hash_table(&hash_table);
}
