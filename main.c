/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/06/27 17:39:13 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// caso falhe algo no parsing temos de dar free na stack inteiro, 
// esta funcao e para isso, 
// podes utilizar para dar free no array se precisares

void	freestack(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || *stack)
		return ;
	(*stack)-> prev -> next = NULL;
	current = *stack;
	while (current != NULL)
	{
		next_node = current -> next;
		free (current);
		current -> next_node;
	}
	*stack = NULL
}
