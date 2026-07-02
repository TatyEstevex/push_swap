/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/02 18:13:35 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parsing_error(t_node **stack)
{
	write (2, "Error\n", 6);
	freestack(stack);
	return (0);
}

int	parsing(int argc, char **argv, t_node **stack_a, int *flag)
{
	int		i;
	long	nb;
	t_node	*node;

	*flag = check_flag(argc, argv);
	if (flag > 0)
		i = 2;
	else
		i = 1;
	while (i < argc)
	{
		if (verifynumb(argv[i]) == 0)
			return (parsing_error(stack_a));
		nb = ft_atoi(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX || (checkdup(*stack_a, nb) == 0))
			return (parsing_error(stack_a));
		node = new_node(nb);
		if (!node)
			return (parsing_error(stack_a));
		add_back(stack_a, node);
		i++;
	}
	return (1);
}

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

static int	check_flag(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(argv[1], "--medium", 8) == 0)
		return (2);
	else if (ft_strncmp(argv[1], "--complex", 8) == 0)
		return (3);
	else if (ft_strncmp(argv[1], "--adaptive", 10) == 0)
		return (4);
	return(0);
}

