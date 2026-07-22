/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:05:45 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 13:02:36 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_unindexed(t_data *data)
{
	t_node	*current;
	t_node	*min;
	int		i;

	current = data->stack_a;
	min = NULL;
	i = 0;
	while (i < data->size_a)
	{
		if (current->index == -1 && (!min || current->value < min->value))
			min = current;
		current = current->next;
		i++;
	}
	return (min);
}

void	init_index_stack(t_data *data)
{
	int		index_size;
	t_node	*current;
	int		i;

	current = data->stack_a;
	i = 0;
	while (i < data->size_a)
	{
		current->index = -1;
		current = current->next;
		i++;
	}
	index_size = 0;
	while (index_size < data->size_a)
	{
		find_min_unindexed(data)->index = index_size;
		index_size++;
	}
}