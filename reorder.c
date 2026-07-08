/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:59:41 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 16:21:15 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_data *data)
{
	int	t;

	t = stack_size(data->stack_a);
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

int	find_position(t_data *data, int value)
{
	t_node *first;
	int pos;
	int	size;

	first = data->stack_a;
	size = stack_size(data->stack_a);
	pos = 0;
	while (pos < size)
	{
		if (first->value < value && value <= first->next->value)
			return (pos + 1);
		if (first->value > first->next->value)
		{
			if (value > first->value || value <= first->next->value)
				return (pos + 1);
		}
		first = first->next;
		pos++;
	} 
   return (0);
}
