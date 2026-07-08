/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:16:39 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 14:31:40 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_data *data)
{
	if(!data->stack_a)
		return;
	data->stack_a = data->stack_a -> next;
	write(1, "ra\n", 3);
	data->moves++;
	data->count_ra++;
}

void	rb(t_data *data)
{
	if (!data->stack_b)
		return;
	data->stack_b = data->stack_b-> next;
	write(1, "rb\n", 3);
	data->moves++;
	data->count_rb++;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	write(1, "rr\n", 3);
	data->moves--;
	data->count_rr++;
}