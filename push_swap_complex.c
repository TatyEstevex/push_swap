/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:12:03 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/17 14:41:58 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
void	push_to_b(t_data *data)
{
	int	chunk_size;
	int	chunk;

	chunk_size = ft_sqrt(data->size_a) * 2;
	chunk = 0;
	while (data->size_a > 3)
	{
		if (data->stack_a->index <= chunk)
		{
			pb(data);
			chunk++;
		}
		else if (data->stack_a->index <= chunk + chunk_size)
		{
			pb(data);
			chunk++;
		}
		else
			ra(data);
	}
}

void	push_swap_complex(t_data *data)
{
	init_index_stack(data);
	push_to_b(data);
	sort_three(data);
	while (data->size_b > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
	}
	fix_top(data);
}
