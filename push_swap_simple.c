/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:28:00 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/17 14:39:36 by tde-alme         ###   ########.fr       */
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
        current = current->next;
    }
}

void	push_swap_simple(t_data *data)
{
	t_node  *cur;
    int     i;

	init_index_stack(data);
	cur = data->stack_a;
    i = 0;
    while (i < data->size_a)
    {
        cur = cur->next;
        i++;
    }
	push_all_to_b(data);
	while (data->size_b > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
		print_stack(data->stack_a);
	}
	fix_top(data);
}

