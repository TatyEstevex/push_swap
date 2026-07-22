/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/15 19:20:54 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_flag(char *argv);

static int	parsing_error(t_data *data)
{
	write(2, "Error\n", 6);
	freestack(&data->stack_a);
	return (0);
}

int	parsing(int argc, char **argv, t_data *data)
{
	int		i;
	int		flag;

	i = 1;
	while (i < argc)
	{
		flag = check_flag(argv[i]);
		if (flag > 0)
		{
			if (flag == 5 && data->bench == 0)
				data->bench = 1;
			else if (flag >= 1 && flag <= 4 && data->flag == 0)
				data->flag = flag;
			else
				return (parsing_error(data));
			i++;
			continue ;
		}
		if (verifynumb(argv[i]) == 0)
			return (parsing_error(data));
		if (!parse_string(argv[i], &data->stack_a))
			return (parsing_error(data));
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
	(*stack)->prev->next = NULL;
	current = *stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

static int	check_flag(char *argv)
{
	if (ft_strncmp(argv, "--simple", 9) == 0 && argv[8] == '\0')
		return (1);
	else if (ft_strncmp(argv, "--medium", 9) == 0 && argv[8] == '\0')
		return (2);
	else if (ft_strncmp(argv, "--complex", 10) == 0 && argv[9] == '\0')
		return (3);
	else if (ft_strncmp(argv, "--adaptive", 11) == 0 && argv[10] == '\0')
		return (4);
	else if (ft_strncmp(argv, "--bench", 8) == 0 && argv[7] == '\0')
		return (5);
	return (0);
}

