/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:28:00 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/14 13:49:02 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//apagar print_stack

void    print_stack(t_node *stack)
{
    t_node  *current;

    if (!stack)
        return ;
    current = stack;
    while (current->next != stack)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("%d\n", current->value);
}

void	push_swap_simple(t_data *data)
{
	init_index_stack(data);
	push_all_to_b(data);
	while (data->size_b > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
		// printf("--- a depois swap ---\n");
		//print_stack(data->stack_a);
	}
	fix_top(data);
	//printf("total movimentos %i\n", data->moves);
}

void	fix_top(t_data *data)
{
	t_node	*current;
	t_node	*min;
	int		pos;
	int		min_pos;

	if (!data || !data->stack_a)
		return ;
	current = data->stack_a->next;
	min = data->stack_a;
	pos = 1;
	min_pos = 0;
	while (current != data->stack_a)
	{
		if (current->index < min->index)
		{
			min = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	rotate_a(data, min_pos);
}