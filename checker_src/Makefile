# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dorphan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 17:52:39 by dorphan           #+#    #+#              #
#    Updated: 2019/11/09 17:56:08 by dorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ../checker

SRC =	checker.c\
		additions_to_main.c\
		check_line.c\
		actions.c\
		concat_arrays.c\
		is_sorted.c\
		work_with_arg.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJ)
		@$(CC) $(FLAGS) $(OBJ) ../libft/libft.a -o $(NAME)
		@echo "\x1b[32;1mchecker successfully compiled\x1b[0m"

%.o: %.c -I
		$(CC) -o $ $(FLAGS) $<

clean:
		@rm -f $(OBJ)

fclean: 	clean
		@rm -f $(NAME)

re: 		fclean all
