/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:28:00 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/01 16:06:11 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_simple(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b)
    {
        calculate_costs(stack_a, stack_b);
        printf("cheapest: %d cost: %d\n", find_cheapest(stack_b)->value, find_cheapest(stack_b)->cost);
        printf("pos_a: %d\n", find_position(stack_a, find_cheapest(stack_b)->value));
        swap_cheapest(stack_a, stack_b);
        printf("--- a depois swap ---\n");
        print_stack(*stack_a);
    }
}

void	fix_top(t_node **stack_a)
{
	t_node	*current;
	t_node	*min;
	int		pos;
	int		min_pos;
	int		size;

	current = *stack_a;
	min = *stack_a;
	pos = 0;
	min_pos = 0;
	size = stack_size(stack_a);
	while (current)
	{
		if(current->value < min->value)
		{
		min = current;
		min_pos = pos;
		}
	current = current->next;
	pos++;
	}
	rotate_a(stack_a, min_pos, size);
}
