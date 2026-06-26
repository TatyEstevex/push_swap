/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:29:07 by josmorei          #+#    #+#             */
/*   Updated: 2026/06/26 18:57:16 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verifynumb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if (str[i] < '0' || str[i] > '9')
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
		return (0);
	if (stack -> value == nb)
		return (1);
	current = stack -> next;
	while (current != stack)
	{
		if (current -> value == nb)
			return (1);
		current = current -> next;
	}
	return (0);
}






