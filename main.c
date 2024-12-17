/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 17:09:42 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	a = initialize_stack(a);
	b = initialize_stack(b);
	parse_input(argc, argv, a);
	check_duplicates(a);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	a = NULL;
	b = NULL;
	exit(EXIT_SUCCESS);
}
