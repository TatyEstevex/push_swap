/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmorei <josmorei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:05:28 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/27 18:08:25 by josmorei         ###   ########.fr       */
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

t_node	*new_node(int value);
int		parsing(int argc, char **argv, t_node **stack_a);
void	freestack(t_node **stack);
void	add_front(t_node **stack, t_node *node);
void	add_back(t_node **stack, t_node *node);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
int 	stack_size(t_node **stack_a);
void    push_all_to_b(t_node **stack_a, t_node **stack_b);
int		find_position(t_node **stack_a, int value);
int		cost_a(int pos_a, int size_a);
int		cost_b(int pos_b, int size_b);
void 	calculate_costs(t_node **stack_a, t_node **stack_b);
t_node	*find_cheapest(t_node **stack_b);
void 	rotate_b(t_node **stack_b, int pos, int size_b);
void    rotate_a(t_node **stack_a, int pos, int size_a);
void	swap_cheapest(t_node **stack_a, t_node **stack_b);
void	push_swap_simple(t_node **stack_a, t_node **stack_b);
void	fix_top(t_node **stack_a);




void	print_stack(t_node *stack); // apagar, para testes

#endif


