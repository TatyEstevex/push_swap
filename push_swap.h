/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:05:28 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/08 16:53:43 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				cost;
}	t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		moves;
	int		count_sa;
	int		count_sb;
	int		count_ss;
	int		count_pa;
	int		count_pb;
	int		count_ra;
	int		count_rb;
	int		count_rr;
	int		count_rra;
	int		count_rrb;
	int		count_rrr;
}	t_data;

t_node	*new_node(int value);
t_node	*remove_node(t_node **stack);
int		parsing(int argc, char **argv, t_node **stack_a, int *flag);
void	freestack(t_node **stack);
void	add_front(t_node **stack, t_node *node);
void	add_back(t_node **stack, t_node *node);
void	pa(t_data *data);
void	pb(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	sort_two(t_data *data);
void	sort_three(t_data *data);
int		stack_size(t_node *stack);
void	push_all_to_b(t_data *data);
int		find_position(t_data *data, int value);
int		cost_a(int pos_a, int size_a);
int		cost_b(int pos_b, int size_b);
void	calculate_costs(t_data *data);
t_node	*find_cheapest(t_data *data);
void	rotate_b(t_data *data, int pos, int size_b);
void	rotate_a(t_data *data, int pos, int size_a);
void	rotate_both(t_data *data, int pos_a, int pos_b,
			int size_a, int size_b);
void	reverse_rotate_both(t_data *data, int pos_a, int pos_b,
			int size_a, int size_b);
void	swap_cheapest(t_data *data);
void	push_swap_simple(t_data *data);
void	fix_top(t_data *data);
float	check_disorder(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	print_stack(t_node *stack); // apagar, para testes

#endif