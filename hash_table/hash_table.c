/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:52:48 by phuocngu          #+#    #+#             */
/*   Updated: 2024/12/19 18:21:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "hash_table.h"

int	hash_function(int value, int num_of_buckets)
{
	if (value == INT_MIN)
		value = INT_MAX;
	else if (value < 0)
		value = -value;
	return (value % num_of_buckets);
}

t_hash_table	*create_hash_table(int num_of_buckets)
{
	t_hash_table	*table;

	table = malloc(sizeof(t_hash_table));
	if (!table)
		return (NULL);
	table->buckets = ft_calloc(sizeof(t_hash_node *), num_of_buckets);
	if (!table->buckets)
	{
		free(table);
		return (NULL);
	}
	table->num_of_buckets = num_of_buckets;
	return (table);
}

int	insert_to_hash_table(t_hash_table *table, int value)
{
	int			index;
	t_hash_node	*current;
	t_hash_node	*new_node;

	if (!table || !table->buckets)
		return (0);
	index = hash_function(value, table->num_of_buckets);
	if (index < 0 || index >= table->num_of_buckets)
		return (0);
	current = table->buckets[index];
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	new_node = malloc(sizeof(t_hash_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = table->buckets[index];
	table->buckets[index] = new_node;
	return (1);
}

void	free_hash_table(t_hash_table **table)
{
	int			i;
	t_hash_node	*current;
	t_hash_node	*temp;

	if (!table || !*table)
		return ;
	i = 0;
	while (i < (*table)->num_of_buckets)
	{
		current = (*table)->buckets[i];
		while (current)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		i++;
	}
	free((*table)->buckets);
	free(*table);
	*table = NULL;
}
