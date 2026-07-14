/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/14 14:42:08 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algorithm(t_data *data, int flag);

int	main(int argc, char **argv)
{
	t_data	data;
	int		flag;

	flag = 0;
	initialize_struct(&data);
	if (argc < 2)
		return (0);
	if (parsing(argc, argv, &data, &flag) == 0)
		return (0);
	data.size_a = stack_size(data.stack_a);
	data.size_b = 0;
	if (check_disorder(&data) > 0)
	{
		if (data.size_a == 2)
			sort_two(&data);
		else if (data.size_a == 3)
			sort_three(&data);
		else if (data.size_a > 3)
			algorithm(&data, 3); //alterar a flag, tive que por um para forcao o simples
	}
	printf("Cheguei aqui!\n");
	print_stack(data.stack_a);
	printf("movimentos : %i \n", data.moves);
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


