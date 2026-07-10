/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/06/24 13:23:02 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 14:07:03 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_node	*temp;

	if (!data || !data->stack_b)
		return ;
	temp = remove_node(&data->stack_b);
	add_front(&data->stack_a, temp);
	write(1, "pa\n", 3);
	data->moves++;
	data->count_pa++;
	data->size_a++;
	data->size_b--;
		// acrescentar um no stack a quando movimento para a a, e no b a mesma coisa, e retirar do que sai
}

void	pb(t_data *data)
{
	t_node	*temp;

	if (!data || !data->stack_a)
		return ;
	temp = remove_node(&data->stack_a);
	add_front(&data->stack_b, temp);
	write(1, "pb\n", 3);
	data->moves++;
	data->count_pb++;
	data->size_a--;
	data->size_b++;
}
