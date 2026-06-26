/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:11:37 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/24 12:53:46 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}

void	add_front(t_node **stack, t_node *node)
{
	if (!node)
		return;
	if (!*stack)
	{
		*stack = node;
		return;
	}
	node -> next = *stack;
	(*stack) -> prev = node;
	*stack = node;
}
void	add_back(t_node **stack, t_node *node)
{
	t_node	*temp;

	if(!node)
		return;
	if(!*stack)
	{
		*stack = node;
		return;
	}
	temp = *stack;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	temp -> next = node;
	node -> prev = temp;
}