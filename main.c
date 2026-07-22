/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/17 14:39:29 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algorithm(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_struct(&data);
	if (argc < 2)
		return (0);
	if (parsing(argc, argv, &data) == 0)
		return (0);
	data.size_a = stack_size(data.stack_a);
	data.size_b = 0;
	data.initial_disorder = check_disorder(&data);
	if (data.initial_disorder > 0)
	{
		if (data.size_a == 2)
			sort_two(&data);
		else if (data.size_a == 3)
			sort_three(&data);
		else if (data.size_a > 3)
			algorithm(&data);
	}
	if (data.flag)
		print_benchmark(&data);
	freestack(&data.stack_a);
	return (1);
}

static void	algorithm(t_data *data)
{
	if (data->flag == 1)
		push_swap_simple(data);
	else if (data->flag == 2)
		push_swap_medium(data);
	else if (data->flag == 3)
		push_swap_complex(data);
	else if (data->flag == 4 || data->flag == 0)
		push_swap_adaptive(data);
}


