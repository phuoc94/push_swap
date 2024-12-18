/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:21:27 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/18 23:25:07 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_number(char *s)
{
    int i = 0;

    if (s[i] == '-' || s[i] == '+')
        i++;
    if (s[i] == '\0')
        return 0;
    while (s[i] != '\0')
    {
        if (!ft_isdigit(s[i]))
            return 0;
        i++;
    }
    return 1;
}


void	parse_single_arg(char *arg, t_stack *stack, t_stack *stack2)
{
	char	**argv2;
	char	*endptr;
	long	res;
	int		i;
	int		is_num;

	argv2 = ft_split(arg, ' ');
	i = 0;
	while (argv2[i])
		i++;
	if(i == 0)
	{
		free_error(&stack, &stack2);
		free_ft_split(argv2);
		exit(EXIT_FAILURE);
	}
	i--;
	while (i >= 0)
	{
		is_num = is_number(argv2[i]);
		res = ft_strtol(argv2[i], &endptr, 10);
		if (endptr == argv2[i] || res > INT_MAX || res < INT_MIN || !is_num)
		{
			print_error();
			free_ft_split(argv2);
			free_error(&stack, &stack2);
			exit(EXIT_FAILURE);
		}
		push(stack, (int)res);
		i--;
	}
	free_ft_split(argv2);
}

void	parse_multiple_args(int argc, char *argv[], t_stack *stack,
		t_stack *stack2)
{
	char	*endptr;
	long	res;

	while (--argc > 0)
	{
		res = ft_strtol(argv[argc], &endptr, 10);
		if (endptr == argv[argc] || res > INT_MAX || res < INT_MIN)
		{
			print_error();
			free_error(&stack, &stack2);
			exit(EXIT_FAILURE);
		}
		push(stack, (int)res);
	}
}

void	parse_input(int argc, char *argv[], t_stack *stack, t_stack *stack2)
{
	if (argc == 2)
		parse_single_arg(argv[1], stack, stack2);
	else
		parse_multiple_args(argc, argv, stack, stack2);
}
