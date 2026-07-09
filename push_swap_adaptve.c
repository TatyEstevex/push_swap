/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_adaptve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:21:15 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/09 11:17:03 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_adaptive(t_data *data)
{
	float	result;

	result = check_disorder(data);
	if (result <= 0.2)
		push_swap_simple(data);
	else if (result > 0.2 && result <= 0.5)
		push_swap_medium(data);
	else
		push_swap_complex (data);
}
