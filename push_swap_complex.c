/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:12:03 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/20 14:23:20 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_bits (t_data *data)
{
	int		contador;
	int		valor;

	contador = 0;
	valor = 1;
	while (valor <= (data->size_a - 1))
	{
		valor = valor * 2;
		contador++;
	}
	return(contador);
}

void radix_pass(t_data *data, int bit)
{
	int	i;
	int	size;

	size = data->size_a;
	i = 0;
	while (i < size)
	{
		if (((data->stack_a->index >> bit) & 1) == 0)
			pb(data);
		else
			ra(data);
		i++;
	}
}

void	push_swap_complex(t_data *data)
{
	int bits;
	int b;
	int	size_b;

	init_index_stack(data);
	bits = ft_bits(data);
	b = 0;
	while (b < bits)
	{
		radix_pass(data, b);
		size_b = data->size_b;
	if (b == bits - 1)
		{
			while (data->size_b > 0)
				pa(data);
		}
		else
		{
			while (size_b > 0)
			{
				if (((data->stack_b->index >> (b + 1)) & 1) == 1)
					pa(data);
				else
					rb(data); 
				size_b--;
			}
		}
		b++;
	}
}
