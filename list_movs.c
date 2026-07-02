/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:11:37 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 09:08:03 by tde-alme         ###   ########.fr       */
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

t_node	*remove_node(t_node **stack)
{
	t_node	*node;

	if (!*stack)
		return (NULL);
	node = *stack;
	if (node->next == node)
		*stack = NULL;
	else
	{
		*stack = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_front(t_node **stack, t_node *node)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		node -> next = node;
		node -> prev = node;
		*stack = node;
		return ;
	}
	first = *stack;
	last = first -> prev;
	node -> next = first;
	node -> prev = last;
	last -> next = node;
	first -> prev = node;
	*stack = node;
}

void	add_back(t_node **stack, t_node *node)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		node -> next = node;
		node -> prev = node;
		*stack = node;
		return ;
	}
	first = *stack;
	last = first -> prev;
	node -> next = first;
	node -> prev = last;
	last -> next = node;
	first -> prev = node;
}
