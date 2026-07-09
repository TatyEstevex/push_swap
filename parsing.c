/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/09 19:05:18 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_flag(char **argv);
static	char	*ft_strchr(const char *s, int c);

static int	parsing_error(t_data *data)
{
	write(2, "Error\n", 6);
	freestack(&data->stack_a);
	return (0);
}

int	parsing(int argc, char **argv, t_data *data, int *flag)
{
	int		i;
	long	nb;
	t_node	*node;

	*flag = check_flag(argv);
	i = 1;
	if (*flag > 0)
		i = 2;
	printf("flag: %d, i: %d\n", *flag, i);
	while (i < argc)
	{
		printf("a verificar: %s\n", argv[i]);
		if (verifynumb(argv[i]) == 0)
			return (parsing_error(data));
		if (ft_strchr(argv[i], ' ') && !parse_string(argv[i], &data->stack_a))
			return (parsing_error(data));
		else
		{
			nb = ft_atoi(argv[i]);
			node = new_node(nb);
			if (!node || (int)nb != nb || !checkdup(data->stack_a, nb))
				return (parsing_error(data));
			add_back(&data->stack_a, node);
		}
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

static int	check_flag(char **argv)
{
	if (ft_strncmp(argv[1], "--simple", 9) == 0 && argv[1][8] == '\0')
		return (1);
	else if (ft_strncmp(argv[1], "--medium", 9) == 0 && argv[1][8] == '\0')
		return (2);
	else if (ft_strncmp(argv[1], "--complex", 10) == 0 && argv[1][9] == '\0')
		return (3);
	else if (ft_strncmp(argv[1], "--adaptive", 11) == 0 && argv[1][10] == '\0')
		return (4);
	return (0);
}

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

