/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:23:02 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 11:23:47 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = remove_node(stack_b);
	add_front(stack_a, temp);
	write(1, "pa\n", 3);
	g_moves++;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = remove_node(stack_a);
	add_front(stack_b, temp);
	write(1, "pb\n", 3);
	g_moves++;
}

