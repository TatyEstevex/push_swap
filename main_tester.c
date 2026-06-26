/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-alme <tde-alm@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:13:35 by tde-alme          #+#    #+#             */
/*   Updated: 2026/06/26 16:33:28 by tde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}
int main(int argc, char **argv)
{
    t_node *stack_a = NULL;
    int     i;

    if (argc < 2)
        return (0);
    i = 1;
    while (i < argc)
    {
        add_back(&stack_a, new_node(atoi(argv[i])));
        i++;
    }
    if (argc == 3)
        sort_two(&stack_a);
    else if (argc == 4)
        sort_three(&stack_a);
    print_stack(stack_a);
    return (0);
}