/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:28:00 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 16:55:38 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_simple(t_data *data)
{
	while (stack_size(data->stack_b) > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
		printf("--- a depois swap ---\n");
		print_stack(data->stack_a);
	}
	fix_top(data);
}

void	fix_top(t_data *data)
{
	t_node	*current;
	t_node	*min;
	int		pos;
	int		min_pos;
	int		size;

	if (!data || !data->stack_a)
		return ;
	current = data->stack_a->next;
	min = data->stack_a;
	pos = 1;
	min_pos = 0;
	size= stack_size(data->stack_a);
	while (current != data->stack_a)
	{
		if (current->value < min->value)
		{
			min = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	rotate_a(data, min_pos, size);
}
