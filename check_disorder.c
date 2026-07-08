/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:02:41 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/08 20:01:15 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	check_disorder(t_data *data)
{
	t_node	*current;
	int		mistakes;
	int		pairs;
	int		size;

	size = stack_size(data->stack_a);
	if (size < 2)
		return (0.0);
	mistakes = 0;
	pairs = size - 1;
	current = *stack_a;
	while (size -1 > 0)
	{
		if (current -> value > current -> next -> value)
			mistakes++;
		current = current -> next;
		size--;
	}
	return ((float) mistakes / pairs);
}
