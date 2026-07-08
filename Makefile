# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: josmorei <josmorei@student.42porto.com>      +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/06/16 16:25:08 by #+#                 #+#    #+#             #
#   Updated: 2026/07/08 15:55:46 by tde-alme           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main_tester.c list_movs.c push.c rotate.c reverse_rotate.c swap.c sort_two_or_three.c \
	stack_size.c calculate_costs.c push_swap_simple.c reorder.c swap_cheapest.c

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
		cc -o $@ $^
%.o: %.c
		cc -Wall -Werror -Wextra -c $< -o $@

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re