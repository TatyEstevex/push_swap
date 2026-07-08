/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:02:41 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/02 16:40:35 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	check_disorder(t_node **stack_a)
{
	t_node	*current;
	t_node	*checker;
	int		mistakes;
	int		pairs;
	int		size;

	size = stack_size(stack_a);
	if (size < 2)
		return (0);
	mistakes = 0;
	pairs = 0;
	current = *stack_a;
	while (size-- > 0)
	{
		checker = current -> next;
		while (checker != *stack_a)
		{
			pairs++;
			if (current -> value > checker -> value)
				mistakes++;
			checker = checker -> next;
		}
		current = current -> next;
	}
	return ((float) mistakes / pairs);
}
