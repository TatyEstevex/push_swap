/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:59:30 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/01 14:58:40 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void rotate_b(t_node **stack_b, int pos, int size_b)
{
	if (pos <= size_b / 2)
	{
		while (pos != 0)
		{
			rb(stack_b);
			pos--;
		}
	}
	else
	{
		pos = size_b - pos;
		while (pos != 0)
			{
				rrb(stack_b);
				pos--;
			}
	}
}
void    rotate_a(t_node **stack_a, int pos, int size_a)
{
	if (pos <= size_a / 2)
	{
		while (pos != 0)
		{
			ra(stack_a);
			pos--;
		}
	}
	else
	{
		pos = size_a - pos;
		while (pos != 0)
			{
				rra(stack_a);
				pos--;
			}
	}
}

void	swap_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node *change;
	t_node *current;
	int		pos;
	int		size_b;
    int     pos_a;
    int     size_a;

    size_a = stack_size(stack_a);	
    size_b = stack_size(stack_b);
	change = find_cheapest(stack_b);
	current = *stack_b;
	pos = 0;
	while(current != change)
	{
		current = current -> next;
		pos++;
	}
    pos_a = find_position(stack_a, change->value);
    rotate_b(stack_b, pos, size_b);
    rotate_a(stack_a, pos_a, size_a);
    pa(stack_a, stack_b);
}