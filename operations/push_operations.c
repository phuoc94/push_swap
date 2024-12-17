/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:18:04 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 17:55:15 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *des, t_stack *src)
{
	if (!src || !src->top || !des)
		return ;
	ft_putstr_fd("pa\n", 1);
	ft_push_to(des, src);
}

void	pb(t_stack *des, t_stack *src)
{
	if (!src || !src->top || !des)
		return ;
	ft_putstr_fd("pb\n", 1);
	ft_push_to(des, src);
}
