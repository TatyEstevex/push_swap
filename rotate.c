/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:16:39 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 09:57:41 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_node **stack_a)
{
	if(!*stack_a)
		return;
	*stack_a = (*stack_a)-> next;
	write(1, "ra\n", 3);
	g_moves++;
}

void	rb(t_node **stack_b)
{
	if (!*stack_b)
		return;
	*stack_b = (*stack_b)-> next;
	write(1, "rb\n", 3);
	g_moves++;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
	g_moves--;
}