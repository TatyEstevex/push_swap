/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:59:41 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/15 12:16:04 by tde-alme         ###   ########.fr       */
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
    //printf("size_a=%d procuro index=%d\n", data->size_a, index);
	while (pos < size)
	{
		//printf("pos=%d first->index=%d first->next->index=%d\n", pos, first->index, first->next->index);
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

	//printf("--- antes fix_top ---\n");
    //print_stack(data->stack_a);
	if (!data || !data->stack_a)
		return ;
	current = data->stack_a->next;
	min = data->stack_a;
	pos = 1;
	min_pos = 0;
	while (current != data->stack_a)
	{
		//printf("pos=%d value=%d index=%d\n", pos, current->value, current->index);
		if (current->index < min->index)
		{
			min = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	//printf("min_pos=%d size_a=%d\n", min_pos, data->size_a);
	rotate_a(data, min_pos);
}
