/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:47:12 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/03 18:56:17 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>


typedef struct s_frame
{
	int				data;
	struct s_frame	*next;
}				t_frame;

typedef struct s_stack
{
	t_frame			*head;
	size_t			size;
}				t_stack;


t_stack *initialize_stack(t_stack **stack);
int pop(t_stack **stack);
t_stack *push(t_stack **stack, int data);

#endif
