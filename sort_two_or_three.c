/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_or_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:31:36 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 14:29:25 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		sa(data);
}

void	sort_three(t_data *data)
{
	int	fst, sec, third;

	fst = data->stack_a->value;
	sec = data->stack_a->next->value;
	third = data->stack_a->prev->value;
	if (fst > sec && fst < third)
		sa(data);
	else if (fst > sec && sec < third)
		ra(data);
	else if (fst > sec)
	{
		sa(data);
		rra(data);
	}
	else if (sec > third && fst < third)
	{
		sa(data);
		ra(data);
	}
	else if (sec > third)
		rra(data);
}
