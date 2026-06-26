/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:42:42 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/26 16:50:36 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int stack_size(t_node **stack_a)
{
    t_node  node;
    int     count;

    node = *stack_a;
    count = 0;
    while(node-> next)
        count = count + node-> next;   
    return (count);        
}
