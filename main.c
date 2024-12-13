/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/13 16:13:02 by phuocngu         ###   ########.fr       */
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
	// push_swap(a, b);
	exit(EXIT_SUCCESS);
}

void	parse_input(int argc, char *argv[], t_stack *stack)
{
	char	**argv2;
	int		i;
	int		res;
	char	*endptr;
	char	*str;

	i = 0;
	if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		while (argv2[i])
			i++;
		i--;
		while (i >= 0)
		{
			str = argv2[i];
			res = ft_strtol(str, &endptr, 10);
			if (endptr == str)
			{
				print_error();
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
			else
				push(stack, res);
			i--;
		}
	}
	else
	{
		while (--argc > 0)
		{
			str = argv[argc];
			res = ft_strtol(str, &endptr, 10);
			if (endptr == str)
			{
				print_error();
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
			else
				push(stack, res);
		}
	}
}
