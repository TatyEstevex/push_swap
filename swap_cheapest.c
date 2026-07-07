/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:59:30 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/07 15:50:46 by tde-alme         ###   ########.fr       */
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

void	rotate_both(t_node **stack_a, t_node **stack_b, int pos_a, int pos_b,
		int size_a, int size_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
    	rr(stack_a, stack_b);
    	pos_a--;
    	pos_b--;
	}
	rotate_a(stack_a, pos_a, size_a);
	rotate_b(stack_b, pos_b, size_b);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b, int pos_a, int pos_b,
		int size_a, int size_b)
{
	pos_a = size_a - pos_a;
	pos_b = size_b - pos_b;

	while (pos_a > 0 && pos_b > 0)
	{
    	rrr(stack_a, stack_b);
    	pos_a--;
    	pos_b--;
	}
	while (pos_a-- > 0)
    	rra(stack_a);
	while (pos_b-- > 0)
    	rrb(stack_b);
}

void	swap_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node *change;
	t_node *current;
	int		pos_b;
	int		size_b;
    int     pos_a;
    int     size_a;

    size_a = stack_size(stack_a);	
    size_b = stack_size(stack_b);
	change = find_cheapest(stack_b);
	current = *stack_b;
	pos_b = 0;
	while(current != change)
	{
		current = current -> next;
		pos_b++;
	}
    pos_a = find_position(stack_a, change->value);
	printf("inserir %d na posicao %d\n", change->value, pos_a);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
		rotate_both(stack_a, stack_b, pos_a, pos_b, size_a, size_b);
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
		reverse_rotate_both(stack_a, stack_b, pos_a, pos_b,
			size_a, size_b);
	else
	{
		rotate_a(stack_a, pos_a, size_a);
		rotate_b(stack_b, pos_b, size_b);
	}
    pa(stack_a, stack_b);
} 