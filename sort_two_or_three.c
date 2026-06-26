/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_or_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:31:36 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/26 16:28:23 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if((*stack_a)-> value > (*stack_a)-> next-> value)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
    t_node	*sec;
    t_node	*third;
    
    sec = (*stack_a)-> next;
	third = sec-> next;
    if(((*stack_a)-> value < sec-> value) && (sec-> value < third-> value))
		return;
	else if(((*stack_a)-> value > third-> value) && (sec-> value > (*stack_a)-> value) && (third-> value < sec-> value))
		rra(stack_a);
	else if(((*stack_a)-> value < sec-> value) && (sec-> value > third-> value) && ((*stack_a)-> value < third-> value))
	{	
		sa(stack_a);
		ra(stack_a);
	}
	else if(((*stack_a)-> value > sec-> value) && (sec-> value < third-> value) && ((*stack_a)-> value < third-> value))
		sa(stack_a);
	else if(((*stack_a)-> value > sec-> value) && (sec-> value < third-> value) && ((*stack_a)-> value > third-> value))
		ra(stack_a);
	else if(((*stack_a)-> value > sec-> value) && (sec-> value > third-> value) && ((*stack_a)-> value > third-> value))
	{	
		sa(stack_a);
		rra(stack_a);
	}
}
