/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:13:35 by tde-alme          #+#    #+#             */
/*   Updated: 2026/07/02 10:03:23 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack)
{
    t_node *first = stack;
    if (!stack)
        return ;
    do
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    } while (stack != first);
}
int main(void)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;

    add_back(&stack_a, new_node(5));
    add_back(&stack_a, new_node(3));
    add_back(&stack_a, new_node(1));
    add_back(&stack_a, new_node(4));
    add_back(&stack_a, new_node(2));
    push_all_to_b(&stack_a, &stack_b);
    printf("--- depois push_all_to_b ---\n");
	printf("movimentos: %d\n", g_moves);
    print_stack(stack_a);
    printf("--- stack b ---\n");
    print_stack(stack_b);
    push_swap_simple(&stack_a, &stack_b);
	printf("movimentos: %d\n", g_moves);
    printf("--- depois push_swap_simple ---\n");
    print_stack(stack_a);
	printf("movimentos: %d\n", g_moves);
    return (0);
}