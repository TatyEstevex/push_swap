/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:42:51 by josmorei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/01 17:57:07 by josmorei         ###   ########.fr       */
=======
/*   Updated: 2026/07/02 11:28:51 by tde-alme         ###   ########.fr       */
>>>>>>> 5300ded876fed99c6118d54758d8deb48058c946
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		size;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	if (parsing(argc, argv, &stack_a) == 0)
		return (0);
	if (sorted(stack_a) == 0)
	{
		size = stack_size(&stack_a);
		if (size == 2)
			sort_two(&stack_a);
		if (size == 3)
			sort_three(&stack_a);
		
	}
	freestack(&stack_a);
	return (1);
}

static	int	sorted(t_node *stack_a)
{
	t_node	*current;

	if (!stack_a)
		return (1);
	current = stack_a;
	while (current -> next != stack_a)
	{
		if (current -> value > current -> next -> value)
			return (0);
		current = current -> next;
	}
	if (current -> value > stack_a -> value)
		return (0);
	return (1);
}

