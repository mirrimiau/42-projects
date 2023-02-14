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


NAME = libftprintf.a
 
FUNCTIONS = ft_printf typetostr attributes attributes_2 attributes_3 width \
width_2 precision flags flags_2 specifiers specifiers_2 specifiers_3 length
INCLUDES = ft_printf.h libft/libft.h
OFILES = $(patsubst %, %.o, $(FUNCTIONS))
CFILES = $(patsubst %, %.c, $(FUNCTIONS))

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	
	make -C libft
	cp libft/libft.a $(NAME)
	gcc $(CFILES) -Wall -Wextra -Werror -g -c -I $(INCLUDES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f *.o
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
