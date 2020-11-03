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

LIBFT = libft/

PS = push_swap_src/

CH = checker_src/

GN = num_genetator_src/

VS = visualizator_src/

all:
		@clear
		@make -C $(LIBFT)
		@make -C $(PS)
		@make -C $(CH)
		@make -C $(GN)
		@make -C $(VS)

clean:
		@make -C $(LIBFT) clean
		@make -C $(PS) clean
		@make -C $(CH) clean
		@make -C $(GN) clean
		@make -C $(VS) clean

fclean: 	clean
		@make -C $(LIBFT) fclean
		@make -C $(PS) fclean
		@make -C $(CH) fclean
		@make -C $(GN) fclean
		@make -C $(VS) fclean

re: 		fclean all
