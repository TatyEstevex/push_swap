/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:23:02 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/26 15:58:00 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_node **stack_a, t_node **stack_b)
{
    t_node  *temp;

    if (!*stack_b)
        return ;
    temp = *stack_b;
    *stack_b = temp-> next;
    if (*stack_b)
        (*stack_b)-> prev = NULL;
    temp-> next = *stack_a;
    if(*stack_a)
        (*stack_a)->prev = temp;
    *stack_a = temp;
	write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
	t_node *temp;

	if (!*stack_a)
		return;
	temp = *stack_a;
	*stack_a = temp-> next;
	if (*stack_a)
		(*stack_a)-> prev = NULL;
	temp-> next = *stack_b;
	if (*stack_b)
		(*stack_b)-> prev = temp;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

