# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 20:46:57 by mapostol          #+#    #+#              #
#    Updated: 2022/01/18 20:46:59 by mapostol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

FUNCTIONS = operations operations2 operations3 operations4 stack_manipulation \
stack_manipulation2 stacksolvers links links2 blocks
INCLUDES = checker.h libft/libft.h
LIBRARY = libft/libft.a
CFILES = $(patsubst %, %.c, $(FUNCTIONS))

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	make -C libft
	gcc checker_main.c $(CFILES) $(LIBRARY) -Wall -Wextra -Werror -g -o checker
	gcc ps_main.c $(CFILES) $(LIBRARY) -Wall -Wextra -Werror -g -o $(NAME)

clean:
	rm -f *.o
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f checker
	make fclean -C libft

re: fclean all
