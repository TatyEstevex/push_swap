/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:10:44 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/26 15:31:03 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  	rra(t_node **stack_a)
{
    t_node	*temp;
    t_node	*last;

	if(!*stack_a)
		return;
	last = *stack_a;
	while(last-> next)
		last = last-> next;
	temp = last-> prev;
	temp-> next = NULL;
	temp = *stack_a;
	*stack_a = last;
	temp-> prev = last;
	last-> next = temp;
	last-> prev = NULL;
	write(1, "rra\n", 4);
} 

void	rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*last;

	if(!*stack_b)
		return;
	last = *stack_b;
	while(last-> next)
		last = last-> next;
	temp = last-> prev;
	temp-> next = NULL;
	temp = *stack_b;
	*stack_b = last;
	last-> prev = NULL;
	last-> next = temp;
	temp-> prev = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}