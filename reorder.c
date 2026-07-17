/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:59:41 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/17 14:39:17 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_data *data)
{
	int	t;

	t = data->size_a;
	if (t <= 3)
	{
		if (t == 3)
			sort_three(data);
		else if (t == 2)
			sort_two(data);
		return ;
	}
	while (t > 3)
	{
		pb(data);
		t--;
	}
	sort_three(data);
}

int	find_position(t_data *data, int index)
{
	t_node	*first;
	int		pos;
	int		size;

	first = data->stack_a;
	size = data->size_a;
	pos = 0;
	while (pos < size)
	{
		if (first->index < index && index <= first->next->index)
			return (pos + 1);
		if (first->index > first->next->index)
		{
			if (index > first->index || index < first->next->index)
				return (pos + 1);
		}
		first = first->next;
		pos++;
	}
	return (size);
}

void	fix_top(t_data *data)
{
	t_node	*current;
	t_node	*min;
	int		pos;
	int		min_pos;

	if (!data || !data->stack_a)
		return ;
	current = data->stack_a->next;
	min = data->stack_a;
	pos = 1;
	min_pos = 0;
	while (current != data->stack_a)
	{
		if (current->index < min->index)
		{
			min = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	rotate_a(data, min_pos);
}
