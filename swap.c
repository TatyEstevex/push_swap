/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:37:13 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 17:11:00 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int *stack_a, int *size_a) //swap top 2 a
{
	int	temp;

	if (*size_a < 2)
		return ;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(int *stack_b, int *size_b) //swap top 2 b
{
	int	temp;

	if (*size_b < 2)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(int *stack_a, int *stack_b, int *size_a, int *size_b) //swap top 2 a & b
{
	sa(stack_a, size_a);
	sb(stack_b, size_b);
}