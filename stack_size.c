/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:42:42 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 09:09:58 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node **stack_a)
{
	t_node	*node;
	int		count;

    t_node  *node;
    int     count;

    node = *stack_a;
    count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return (count);
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
