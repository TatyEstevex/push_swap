/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:06:28 by josmorei          #+#    #+#             */
/*   Updated: 2026/07/17 13:03:54 by tde-alme         ###   ########.fr       */
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

static void	print_stratey(t_data *data)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (data->flag == 1)
		ft_putstr_fd("Simple\n", 2);
	else if (data->flag == 2)
		ft_putstr_fd("Medium\n", 2);
	else if (data->flag == 3)
		ft_putstr_fd("Complex\n", 2);
	else
		ft_putstr_fd("Adaptive O(n * log n)\n", 2);

}

void	print_benchmark(t_data *data)
{
	float	disorder;
	int		dec_part;

	if (!data->bench)
		return ;
	disorder = data->initial_disorder * 100.0;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)disorder, 2);
	ft_putchar_fd('.', 2);
	dec_part = (int)((disorder - (int)disorder) * 100);
	if (dec_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
	print_stratey(data);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->moves, 2);
	ft_putchar_fd('\n', 2);
	print_individual_counts(data);
}
