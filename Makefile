# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: tde-alme <tde-alm@student.42porto.com>       +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/06/16 16:25:08 by ei                  #+#    #+#             #
#   Updated: 2026/06/26 16:53:32 by tde-alme           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main_tester.c list_movs.c push.c rotate.c reverse_rotate.c swap.c sort_two_or_three.c
	stack_size.c 

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