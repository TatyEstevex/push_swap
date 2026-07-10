/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:25:01 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/10 10:52:05 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_data *data, int pos)
{
	if (pos <= data->size_b / 2)
	{
		while (pos != 0)
		{
			rb(data);
			pos--;
		}
	}
	else
	{
		pos = data->size_b - pos;
		while (pos != 0)
		{
			rrb(data);
			pos--;
		}
	}
}

void	rotate_a(t_data *data, int pos)
{
	if (pos <= data->size_a / 2)
	{
		while (pos != 0)
		{
			ra(data);
			pos--;
		}
	}
	else
	{
		pos = data->size_a - pos;
		while (pos != 0)
		{
			rra(data);
			pos--;
		}
	}
}

void	rotate_both(t_data *data, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		rr(data);
		pos_a--;
		pos_b--;
	}
	rotate_a(data, pos_a);
	rotate_b(data, pos_b);
}

void	reverse_rotate_both(t_data *data, int pos_a, int pos_b)
{
	pos_a = data->size_a - pos_a;
	pos_b = data->size_b - pos_b;
	while (pos_a > 0 && pos_b > 0)
	{
		rrr(data);
		pos_a--;
		pos_b--;
	}
	while (pos_a-- > 0)
		rra(data);
	while (pos_b-- > 0)
		rrb(data);
}
