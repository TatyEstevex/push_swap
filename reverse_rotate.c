/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:10:44 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/15 19:41:30 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (!data->stack_a)
		return ;
	data->stack_a = data->stack_a->prev;
	write(1, "rra\n", 4);
	data->moves++;
	data->count_rra++;
}

void	rrb(t_data *data)
{
	if (!data->stack_b)
		return ;
	data->stack_b = data->stack_b->prev;
	write(1, "rrb\n", 4);
	data->moves++;
	data->count_rrb++;
}

void	rra_silent(t_data *data)
{
	if (!data->stack_a)
		return ;
	data->stack_a = data->stack_a->prev;
	data->moves++;
	data->count_rra++;
}

void	rrb_silent(t_data *data)
{
	if (!data->stack_b)
		return ;
	data->stack_b = data->stack_b->prev;
	data->moves++;
	data->count_rrb++;
}

void	rrr(t_data *data)
{
	rra_silent(data);
	rrb_silent(data);
	write(1, "rrr\n", 4);
	data->moves--;
	data->count_rrr++;
}
