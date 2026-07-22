# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: tde-alme <tde-alme@student.42porto.com>      +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/06/16 16:25:08 by +#                  #+#    #+#             #
#   Updated: 2026/07/17 12:43:38 by tde-alme           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c list_movs.c push.c rotate.c reverse_rotate.c swap.c sort_two_or_three.c \
	stack_size.c calculate_costs.c reorder.c swap_cheapest.c rotate_stacks.c \
	benchmark.c check_disorder.c pars-utils.c parsing.c push_swap_adaptive.c push_swap_complex.c \
	push_swap_medium.c push_swap_simple.c initialize_struct.c index.c benchmark_utils.c

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
		cc -o $@ $^
%.o: %.c
		cc -Wall -Werror -Wextra -c $< -o $@ -g

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
	make clean

.PHONY: all clean fclean re