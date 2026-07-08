/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:10:44 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 14:31:54 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  	rra(t_data *data)
{
	if(!data->stack_a)
		return;
	data-> stack_a = data->stack_a-> prev;
	write(1, "rra\n", 4);
	data->moves++;
	data->count_rra++;
} 

void	rrb(t_data *data)
{
	if(!data->stack_b)
		return;
	data->stack_b = data->stack_b->prev;
	write(1, "rrb\n", 4);
	data->moves++;
	data->count_rrb++;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	data->moves--;
	data->count_rrr++;
}