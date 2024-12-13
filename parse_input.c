/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:21:27 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/13 19:11:58 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_single_arg(char *arg, t_stack *stack)
{
	char	**argv2;
	char	*endptr;
	long	res;
	int		i;

	argv2 = ft_split(arg, ' ');
	i = 0;
	while (argv2[i])
		i++;
	i--;
	while (i >= 0)
	{
		res = ft_strtol(argv2[i], &endptr, 10);
		if (endptr == argv2[i] || res > INT_MAX || res < INT_MIN)
		{
			print_error();
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		push(stack, (int)res);
		i--;
	}
}

void	parse_multiple_args(int argc, char *argv[], t_stack *stack)
{
	char	*endptr;
	long	res;

	while (--argc > 0)
	{
		res = ft_strtol(argv[argc], &endptr, 10);
		if (endptr == argv[argc] || res > INT_MAX || res < INT_MIN)
		{
			print_error();
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		push(stack, (int)res);
	}
}

void	parse_input(int argc, char *argv[], t_stack *stack)
{
	if (argc == 2)
		parse_single_arg(argv[1], stack);
	else
		parse_multiple_args(argc, argv, stack);
}
