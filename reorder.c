/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:59:41 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 11:28:45 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_node **stack_a, t_node **stack_b)
{
	int	t;

	t = stack_size(stack_a);
	while (t > 3)
	{
		pb(stack_a, stack_b);
		t--;
	}
	if (t == 3)
		sort_three(stack_a);
	else if (t == 2)
		sort_two(stack_a);
}

int	find_position(t_node **stack_a, int value)
{
	t_node	*first;
	int		pos;

	first = *stack_a;
	pos = 0;
	if (value < first->value)
		return (0);
	while (first->next != *stack_a)
	{
		if (first->value < value && value < first->next->value)
			return (pos + 1);
		first = first->next;
		pos++;
	}
	return (0);
}
