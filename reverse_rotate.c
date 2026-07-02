/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:10:44 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 09:56:50 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  	rra(t_node **stack_a)
{
	if(!*stack_a)
		return;
	*stack_a = (*stack_a)-> prev;
	write(1, "rra\n", 4);
	g_moves++;
} 

void	rrb(t_node **stack_b)
{
	if(!*stack_b)
		return;
	*stack_b = (*stack_b)->prev;
	write(1, "rrb\n", 4);
	g_moves++;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
	g_moves--;
}