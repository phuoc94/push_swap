/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:47:12 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/18 21:44:12 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./lis/lis.h"
# include <stdbool.h>

typedef struct s_frame
{
	int				data;
	int				current_position;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_frame	*target_node;
	struct s_frame	*next;
}					t_frame;

typedef struct s_stack
{
	t_frame			*top;
	int				size;
}					t_stack;

int					is_stack_sorted(t_stack *stack);
void				push_swap(t_stack *a, t_stack *b);
void				parse_input(int argc, char *argv[], t_stack *stack,
						t_stack *stack2);

t_stack				*initialize_stack(t_stack *stack);
void				free_stack(t_stack *stack);

int					pop(t_stack *stack);
t_stack				*push(t_stack *stack, int data);

void				ft_swap(t_stack *stack);
void				ft_push_to(t_stack *des, t_stack *src);
void				ft_shift_down(t_stack *stack);
void				ft_shift_up(t_stack *stack);

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
void				check_duplicates(t_stack *stack, t_stack *stack2);

void				print_error(void);
void				free_error(t_stack **a, t_stack **b);
int					*get_lis(t_stack *stack, int *length);

int					*stack_to_array(t_stack *stack);
void				print_arr(int *arr, int size);
int					get_max_index(int *arr, int size);

void				move_non_lis_to_b(t_stack *a, t_stack *b, int *arr,
						int lis_length);

void				set_nodes_data(t_stack *a, t_stack *b);
t_frame				*find_target_node(t_stack *target_stack,
						t_frame *current_b);
t_frame				*find_smallest(t_stack *stack);
void				set_current_position(t_stack *stack);
void				push_cheapest(t_stack *a, t_stack *b);

void				print_node_data(t_frame *node);

#endif
