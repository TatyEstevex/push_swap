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
	}
	fix_top(data);
}

void	push_chunk(t_data *data)
{
	int	size;
	int	chunk_size;
	int	current_limit;

	init_index_stack(data);
	size = stack_size(data->stack_a);
	chunk_size = (size / 6);
		if (chunk_size < 1)
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
	sort_three(data);
}

