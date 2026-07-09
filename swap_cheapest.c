/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:59:30 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/09 10:34:36 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos_b(t_node *stack_b, t_node *change)
{
	t_node	*current;
	int		pos;

	current = stack_b;
	pos = 0;
	while (current != change)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

void	swap_cheapest(t_data *data)
{
	t_node	*change;
	int		pos_a;
	int		pos_b;
	t_sizes	sizes;

	sizes.a = stack_size(data->stack_a);
	sizes.b = stack_size(data->stack_b);
	change = find_cheapest(data);
	pos_b = find_pos_b(data->stack_b, change);
	pos_a = find_position(data, change->value);
	printf("inserir %d na posicao %d\n", change->value, pos_a);
	if (pos_a <= sizes.a / 2 && pos_b <= sizes.b / 2)
		rotate_both(data, pos_a, pos_b, sizes);
	else if (pos_a > sizes.a / 2 && pos_b > sizes.b / 2)
		reverse_rotate_both(data, pos_a, pos_b, sizes);
	else
	{
		rotate_a(data, pos_a, sizes.a);
		rotate_b(data, pos_b, sizes.b);
	}
	pa(data);
}
