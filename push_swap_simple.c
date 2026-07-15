/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:28:00 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/15 16:30:30 by josmorei         ###   ########.fr       */
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
        //printf("%d\n", current->value);
        current = current->next;
    }
    //printf("%d\n", current->value);
}

void	push_swap_simple(t_data *data)
{
	t_node  *cur;
    int     i;

	init_index_stack(data);
	//printf("indices depois init:\n");
	//print_stack(data->stack_a);
	cur = data->stack_a;
    i = 0;
    while (i < data->size_a)
    {
        //printf("value=%d index=%d\n", cur->value, cur->index);
        cur = cur->next;
        i++;
    }
	push_all_to_b(data);
	//print_stack(data->stack_a);    
	//printf("--- stack b ---\n");
    //print_stack(data->stack_b);
	while (data->size_b > 0)
	{
		calculate_costs(data);
		swap_cheapest(data);
		//printf("--- a depois swap ---\n");
		print_stack(data->stack_a);
	}
	fix_top(data);
	//printf("total movimentos %i\n", data->moves);
}

