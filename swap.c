/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:37:13 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 09:59:33 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a) //swap top 2 a
{
	int	temp;

	if ((!*stack_a) || ((*stack_a) -> next == *stack_a))
		return ;
	temp = (*stack_a)-> value;
	(*stack_a)-> value = (*stack_a)-> next -> value;
	(*stack_a)-> next -> value = temp;
	write(1, "sa\n", 3);
	g_moves++;
}

void	sb(t_node **stack_b) //swap top 2 b
{
	int	temp;

	if ((!*stack_b) || ((*stack_b) -> next == *stack_b))
		return ;
	temp = (*stack_b)-> value;
	(*stack_b)-> value = (*stack_b)-> next -> value;
	(*stack_b)-> next -> value = temp;
	write(1, "sb\n", 3);
	g_moves++;
}

void	ss(t_node **stack_a, t_node **stack_b) //swap top 2 a & b
{
	sa(stack_a);
	sb(stack_b);
	g_moves--;
}
