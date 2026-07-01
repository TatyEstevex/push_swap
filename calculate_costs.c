/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:40:32 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/01 14:58:45 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(int pos_a, int size_a)
{
	if (pos_a <= size_a/2)
		return (pos_a);
	return (size_a - pos_a);
}

int	cost_b(int pos_b, int size_b)
{
	if (pos_b <= size_b / 2)
		return (pos_b);
	return (size_b - pos_b);
}
void calculate_costs(t_node **stack_a, t_node **stack_b)
{
    int     size_a;
    int     size_b;
    int     pos_b;
    t_node  *current;

    size_a = stack_size(stack_a);
    size_b = stack_size(stack_b);
    pos_b = 0;
	current = *stack_b;
    while (current)
    {
        current-> cost = cost_b(pos_b, size_b) + cost_a (find_position(stack_a, current -> value), size_a);     
        current = current -> next;
		pos_b++;
    }
}
t_node	*find_cheapest(t_node **stack_b)
{
	t_node	*cheapest;
	t_node	*current;

	cheapest = *stack_b;
	current = (*stack_b)->next;
	while (current)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
