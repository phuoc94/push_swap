/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:49:01 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/17 15:39:59 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIS_H
# define LIS_H

typedef struct s_lis
{
	int					*arr;
	int					arr_size;
	int					*lis;
	int					*prev_index;
	int					lis_size;
	int					max_index;
}						t_lis;

int	is_in_lis(int data, int *lis, int lis_length);

#endif
