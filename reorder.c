/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:59:41 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 12:39:16 by tde-alme         ###   ########.fr       */
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
			if (index > first->index || index <= first->next->index)
				return (pos + 1);
		}
		first = first->next;
		pos++;
	}
	return (0);
}
