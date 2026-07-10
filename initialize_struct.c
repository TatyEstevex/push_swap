/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:43:44 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/10 11:51:10 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_struct(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->moves = 0;
	data->count_sa = 0;
	data->count_sb = 0;
	data->count_ss = 0;
	data->count_pa = 0;
	data->count_pb = 0;
	data->count_ra = 0;
	data->count_rb = 0;
	data->count_rr = 0;
	data->count_rra = 0;
	data->count_rrb = 0;
	data->count_rrr = 0;
}