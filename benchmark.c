/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:06:28 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/16 19:25:29 by josmorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_rotations(t_data *data)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(data->count_ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->count_rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->count_rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->count_rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->count_rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->count_rrr, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_individual_counts(t_data *data)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(data->count_sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->count_sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->count_ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->count_pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->count_pb, 2);
	ft_putchar_fd('\n', 2);
	print_rotations(data);
}

void	print_benchmark(t_data *data)
{
	float	disorder;
	int		dec_part;

	if (!data->bench)
		return ;
	disorder = check_disorder(data) * 100.0;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)disorder, 2);
	ft_putchar_fd('.', 2);
	dec_part = (int)((disorder - (int)disorder) * 100);
	if (dec_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: Adaptive O(n * log n)\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->moves, 2);
	ft_putchar_fd('\n', 2);
	print_individual_counts(data);
}
