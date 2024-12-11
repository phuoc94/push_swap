/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:47:12 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/12 00:54:52 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h> // write

typedef struct s_frame
{
	int				data;
	struct s_frame	*next;
}					t_frame;

typedef struct s_stack
{
	t_frame			*top;
	size_t			size;
}					t_stack;

t_stack				*initialize_stack(t_stack *stack);

int					pop(t_stack *stack);
t_stack				*push(t_stack *stack, int data);

void				ft_swap(t_stack *stack);
void				ft_push_to(t_stack *des, t_stack *src);
void				ft_shift_down(t_stack *stack);
void				ft_shift_up(t_stack *stack);

int					is_stack_sorted(t_stack *stack);
void				push_swap(t_stack *a, t_stack *b);

void				sa(t_stack *stack);
void				sb(t_stack *stack);
void				ss(t_stack *stack1, t_stack *stack2);
void				pa(t_stack *des, t_stack *src);
void				pb(t_stack *des, t_stack *src);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack1, t_stack *stack2);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack1, t_stack *stack2);

void				print_stacks(t_stack *stack1, t_stack *stack2);

#endif
