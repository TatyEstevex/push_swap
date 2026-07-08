/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_adaptve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:21:15 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/08 12:41:48 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_adaptive(t_node **stack_a, t_node **stack_b)
{
	float	result;

	result = check_disorder(stack_a);
	if (result <= 0.2)
		push_swap_simple(stack_a, stack_b);
	else if (result > 0.2 && result <= 0.5)
		push_swap_medium(stack_a, stack_b);
	else
		push_swap_complex (stack_a, stack_b);
}
