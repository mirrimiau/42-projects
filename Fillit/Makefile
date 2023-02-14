# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapostol <mapostol@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 20:46:57 by mapostol          #+#    #+#              #
#    Updated: 2022/01/22 16:15:37 by vkinnune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c fillit.c fillit_solver.c fillit_functions.c \
checkval.c checkval2.c checkval3.c libft/libft.a

FLAGS = -Wall -Wextra -Werror -o

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	gcc  $(SRCS) $(FLAGS) $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
