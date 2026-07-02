/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:42:42 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 15:11:45 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node **stack_a)
{
	t_node	*node;
	int		count;

	if (!*stack_a)
		return (0);
	node = *stack_a;
	count = 1;
	while (node->next != *stack_a)
	{
		node = node->next;
		count++;
	}
	return (count);
}
