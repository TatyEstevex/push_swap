/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/08 14:44:27 by josmorei         ###   ########.fr       */
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
	stack_b = NULL;
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
			algorithm(&stack_a, &stack_b, flag);
	}
	freestack(&stack_a);
	return (1);
}

static void	algorithm(t_node **stack_a, t_node **stack_b, int flag)
{
	if (flag == 1)
		push_swap_simple(&stack_a, &stack_b);
	else if (flag == 2)
		push_swap_medium(&stack_a, &stack_b);
	else if (flag == 3)
		push_swap_complex(&stack_a, stack_b);
	else if (flag == 4 || flag == 0)
		push_swap_adaptive(&stack_a, stack_b);
}


