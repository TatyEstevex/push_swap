/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:37:13 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 16:08:30 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data) //swap top 2 a
{
	int	temp;

	if (!data->stack_a || data->stack_a->next == data->stack_a)
		return ;
	temp = data->stack_a-> value;
	data->stack_a-> value = data->stack_a-> next -> value;
	data->stack_a-> next -> value = temp;
	write(1, "sa\n", 3);
	data->moves++;
	data->count_sa++;
}

void	sb(t_data *data) //swap top 2 b
{
	int	temp;

	if (!data->stack_b || data->stack_b->next == data->stack_b)
		return ;
	temp = data-> stack_b-> value;
	data->stack_b-> value = data-> stack_b-> next -> value;
	data->stack_b-> next -> value = temp;
	write(1, "sb\n", 3);
	data->moves++;
	data->count_sb++;
}

void	ss(t_data *data) //swap top 2 a & b
{
	sa(data);
	sb(data);
	data->moves--;
	data->count_ss++;
}
