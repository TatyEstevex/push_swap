# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: josmorei <josmorei@student.42porto.com>      +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/06/16 16:25:08 by smorei              #+#    #+#             #
#   Updated: 2026/06/16 16:38:04 by josmorei           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = 

OFILES = $(SRC: .c= .o)

all: $(NAME)

$(NAME): $(OFILES)
		ar rcs $@ $^
%.o: %.c
		cc -Wall -Werror -Wextra -c $< -o $@

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re