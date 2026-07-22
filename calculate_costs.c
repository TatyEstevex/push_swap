/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:40:32 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 12:38:32 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(int pos_a, int size_a)
{
	if (pos_a <= size_a / 2)
		return (pos_a);
	return (size_a - pos_a);
}

int	cost_b(int pos_b, int size_b)
{
	if (pos_b <= size_b / 2)
		return (pos_b);
	return (size_b - pos_b);
}

static int	get_total_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	ca;
	int	cb;

	ca = cost_a(pos_a, size_a);
	cb = cost_b(pos_b, size_b);
	if ((pos_a <= size_a / 2 && pos_b <= size_b / 2) || (pos_a > size_a / 2
			&& pos_b > size_b / 2))
	{
		if (ca > cb)
			return (ca);
		return (cb);
	}
	return (ca + cb);
}

void	calculate_costs(t_data *data)
{
	int		size_a;
	int		size_b;
	int		pos_b;
	t_node	*current;

	if (!data->stack_b)
		return ;
	size_a = stack_size(data->stack_a);
	size_b = stack_size(data->stack_b);
	pos_b = 0;
	current = data->stack_b;
	while (pos_b < size_b)
	{
		current->cost = get_total_cost(find_position(data, current->index),
				pos_b, size_a, size_b);
		current = current->next;
		pos_b++;
	}
}

t_node	*find_cheapest(t_data *data)
{
	t_node	*cheapest;
	t_node	*current;

	if (!data->stack_b)
		return (NULL);
	cheapest = data->stack_b;
	current = data->stack_b->next;
	while (current != data->stack_b)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
