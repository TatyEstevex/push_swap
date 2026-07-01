/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/06/27 18:42:32 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parsing_error(t_node **stack)
{
	write (2, "Error\n", 6);
	freestack(stack);
	return (0);
}

int	parsing(int argc, char **argv, t_node **stack_a)
{
	int		i;
	long	nb;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		if (verifynumb(argv[i]) == 0)
			return (parsing_error(stack_a));
		nb = ft_atoi(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX || (checkdup(*stack_a, nb) == 1))
			return (parsing_error(stack_a));
		node = new_node(nb);
		if (!node)
			return (parsing_error(stack_a));
		add_to_back(stack_a, node);
		i++;
	}
	return (1);
}
// caso falhe algo no parsing temos de dar free na stack inteiro, 
// esta funcao e para isso, 
// podes utilizar para dar free no array se precisares

void	freestack(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || !*stack)
		return ;
	(*stack)-> prev -> next = NULL;
	current = *stack;
	while (current != NULL)
	{
		next_node = current -> next;
		free (current);
		current = next_node;
	}
	*stack = NULL;
}


