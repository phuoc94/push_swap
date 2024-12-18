/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:11:16 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/18 21:42:29 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack **a, t_stack **b)
{
	free_stack(*a);
	free_stack(*b);
	free(*a);
	free(*b);
	*a = NULL;
	*b = NULL;
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}
