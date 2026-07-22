/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/15 17:19:28 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verifynumb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i > 0 && str[i - 1] != ' ')
				return (0);
			if ((str[i + 1] < '0' || str[i + 1] > '9') && str[i] != ' ')
				return (0);
		}
		else if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

int	checkdup(t_node *stack, int nb)
{
	t_node	*current;

	if (!stack)
		return (1);
	if (stack->value == nb)
		return (0);
	current = stack->next;
	while (current != stack)
	{
		if (current->value == nb)
			return (0);
		current = current->next;
	}
	return (1);
}

int	parse_string(char *str, t_node **stack_a)
{
	int		i;
	long	nb;
	t_node	*node;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			nb = ft_atoi(&str[i]);
			node = new_node(nb);
			if (!node || (int)nb != nb || !checkdup(*stack_a, nb))
				return (free(node), 0);
			add_back(stack_a, node);
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < (n - 1) && s1[i])
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
