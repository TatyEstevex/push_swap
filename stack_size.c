/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:42:42 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/27 16:28:31 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_node **stack_a)
{
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
}
