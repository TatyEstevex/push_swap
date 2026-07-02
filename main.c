/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/01 11:07:02 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (parsing(argc, argv, &stack_a) == 0)
		return (0);
	if (sorted(stack_a) == 0)
	{

	}
	freestack(&stack_a);
	return (1);
}

static	int	sorted(t_node *stack_a)
{
	t_node	*current;

	if (!stack_a)
		return (1);
	current = stack_a;
	while (current -> next != stack_a)
	{
		if (current -> value > current -> next -> value)
			return (0);
		current = current -> next;
	}
	if (current -> value > stack_a -> value)
		return (0);
	return (1);
}

