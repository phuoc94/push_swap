/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:49:01 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/13 19:03:41 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

typedef struct s_hash_node
{
	int					value;
	struct s_hash_node	*next;
}						t_hash_node;

typedef struct s_hash_table
{
	t_hash_node			**buckets;
	int					num_of_buckets;
}						t_hash_table;

t_hash_table	*create_hash_table(int num_of_buckets);
int				insert_to_hash_table(t_hash_table *table, int value);
void			free_hash_table(t_hash_table *table);

#endif
