/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:16:39 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/25 17:03:06 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_node **stack_a)
{
	t_node *temp;
	t_node *last;

	if(!*stack_a)
		return;
	temp = *stack_a;
	*stack_a = temp-> next;
	if(*stack_a)
		*stack_a-> prev = NULL;
	last = *stack_a;
	while(last-> next)
		last = last-> next;
	last-> next = temp;
	temp-> next = NULL;
	temp-> prev = last;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*last;

	if (!*stack_b)
		return;
	temp = *stack_b;
	*stack_b = temp-> next;
	if(*stack_b)
		*stack_b-> prev = NULL;
	last = *stack_b;
	while(last-> next)
		last = last-> next;
	last-> next = temp;
	temp-> prev = last;
	temp-> next = NULL;
	write(1, "rb\n", 3)
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}