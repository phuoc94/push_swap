/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:47:30 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/16 22:19:36 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	push_swap(t_stack *a, t_stack *b)
{
	int		*lis;
	int		lis_length;

	lis = get_lis(a, &lis_length);
	//move_non_lis_to_b(a, b, lis, lis_length);
	(void)b;


}
