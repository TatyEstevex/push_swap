/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/09 12:49:00 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algorithm(t_data *data, int flag);

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;
	int		flag;

	data.stack_a = NULL;
	data.stack_b = NULL;
	flag = 0;
	if (argc < 2)
		return (0);
	if (parsing(argc, argv, &data, &flag) == 0)
		return (0);
	if (check_disorder(&data) > 0)
	{
		size = stack_size(data.stack_a);
		if (size == 2)
			sort_two(&data);
		else if (size == 3)
			sort_three(&data);
		else if (size > 3)
			algorithm(&data, 1); //alterar a flag, tive que por um para forcao o simples
	}
	print_stack(data.stack_a);
	freestack(&data.stack_a);
	return (1);
}

static void	algorithm(t_data *data, int flag)
{
	if (flag == 1)
		push_swap_simple(data);
	else if (flag == 2)
		push_swap_medium(data);
	else if (flag == 3)
		push_swap_complex(data);
	else if (flag == 4 || flag == 0)
		push_swap_adaptive(data);
}


