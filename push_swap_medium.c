// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_medium.c                                 :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/07/09 19:45:32 by josmorei          #+#    #+#             */
// /*   Updated: 2026/07/09 21:17:11 by josmorei         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

void	push_swap_medium(t_data *data)
{
	push_chunk(data);
	while (stack_size(data->stack_b) > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
		print_stack(data->stack_a); /*apagar para testes*/
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
	size = stack_size(data->stack_a);
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
	rotate_a(data, min_pos);
}

void	push_chunk(t_data *data)
{
	int	size;
	int	chunk_size;
	int	current_limit;

	index_stack(data);
	size = stack_size(data->stack_a);
	chunk_size = (size / 100) * 7 + 13;
	current_limit = chunk_size;
	while (stack_size(data->stack_a) > 3)
	{
		if (data->stack_a->index < current_limit)
		{
			pb(data);
			if (stack_size(data->stack_b) == current_limit)
				current_limit += chunk_size;
		}
		else
			ra(data);
	}
}

void	index_stack(t_data *data)
{
	t_node	*current;
	t_node	*compare;
	int		size_out;
	int		size_in;
	int		count;

	size_out = stack_size(data->stack_a);
	current = data->stack_a;
	while (size_out-- > 0)
	{
		count = 0;
		compare = data->stack_a;
		size_in = stack_size(data->stack_a);
		while (size_in-- > 0)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}
