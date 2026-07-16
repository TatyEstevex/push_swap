/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:02:41 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/16 18:18:16 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	check_disorder(t_data *data)
{
	t_node	*current;
	t_node	*compare;
	int		mistakes;
	int		total_pairs;
	int		size;

	size = stack_size(data->stack_a);
	if (size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = data->stack_a;
	while (--size > 0)
	{
		compare = current->next;
		while (compare != data->stack_a)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return ((float)mistakes / total_pairs);
}
