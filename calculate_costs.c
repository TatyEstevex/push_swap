/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:40:32 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/07 16:19:13 by tde-alme         ###   ########.fr       */
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
	if ((pos_a <= size_a / 2 && pos_b <= size_b / 2)
		|| (pos_a > size_a / 2 && pos_b > size_b / 2))
	{
		if (ca > cb)
			return (ca);
		return (cb);
	}
	return (ca + cb);
}
void	calculate_costs(t_node **stack_a, t_node **stack_b)
{
	int		size_a;
	int		size_b;
	int		pos_b;
	t_node	*current;

	if (!stack_b || !*stack_b)
		return ;
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	pos_b = 0;
	current = *stack_b;
	do
	{
		current->cost = get_total_cost(
		find_position(stack_a, current->value),
		pos_b, size_a, size_b);
		current = current->next;
		pos_b++;
	} while (current != *stack_b);
}

t_node	*find_cheapest(t_node **stack_b)
{
	t_node	*cheapest;
	t_node	*current;

	cheapest = *stack_b;
	current = (*stack_b)->next;
	while (current != *stack_b)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}