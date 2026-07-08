/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:02:41 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/08 15:45:02 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	check_disorder(t_data *data)
{
	t_node	*current;
	t_node	*checker;
	int		mistakes;
	int		pairs;
	int		size;

	size = stack_size(data->stack_a);
	if (size < 2)
		return (0);
	mistakes = 0;
	pairs = 0;
	current = data->stack_a;
	while (size-- > 0)
	{
		checker = current -> next;
		while (checker != data->stack_a)
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
