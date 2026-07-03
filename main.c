/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/03 19:20:11 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		flag;

	stack_a = NULL;
	flag = 0;
	if (argc < 2)
		return (0);
	if (parsing(argc, argv, &stack_a, &flag) == 0)
		return (0);
	if (check_disorder(&stack_a) > 0)
	{
		size = stack_size(&stack_a);
		if (size == 2)
			sort_two(&stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else if (size > 3)
			algorithm(*stack_a, flag);
	}
	freestack(&stack_a);
	return (1);
}

static void	algorithm(t_node stack_a, t_node stack_b int flag)
{
	if (flag == 1)
		return ;
	else if (flag == 2)
		return ;
	else if (flag == 3)
		return ;
	else if (flag == 4)
		return ;
}

