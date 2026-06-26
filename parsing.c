/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/06/26 18:54:47 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **argv, t_node **stack_a)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		verifynumb(argv[i]);
		if (verifynumb(argv[i]) == 0)
		{
			write (2, "Error\n", 6);
			free (stack_a);
			return (0);
		}
		nb = ft_atoi(argv[1]);
		if (nb < INT_MIN || nb > __INT_MAX__ || (checkdup(*stack_a, nb) == 1))
		{
			write (2, "Error\n", 6);
			free (stack_a);
			return (1);
		}
		i++;
	}
	return (1);
}



