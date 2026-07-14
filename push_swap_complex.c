/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:12:03 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/14 14:40:13 by tde-alme         ###   ########.fr       */
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

	chunk_size = ft_sqrt(data->size_a);
	chunk = 0;
	while (data->stack_a)
	{
		if (data->stack_a->index < (chunk + 1) * chunk_size)
		{
			pb(data);
		}
		else
		{
			ra(data);
		}

		if (data->size_b == (chunk + 1) * chunk_size)
			chunk++;
	}
}

void	push_swap_complex(t_data *data)
{
	init_index_stack(data);
	push_to_b(data);
	printf("--- stack a ---\n");
	print_stack(data->stack_a);
	printf("--- stack b ---\n");
	print_stack(data->stack_b);
	while (data->size_b > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
		fix_top(data);
	}
}
