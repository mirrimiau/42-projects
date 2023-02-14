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


NAME = mapostol.filler

FILES = main parsing solving heatmap

CFILES = $(patsubst %, %.c, $(FILES))
SRCS = $(CFILES)
SRC_DIR = src/
OBJ = $(SRCS:.c=.o)
OBJ_DIR = obj/
INCLUDES = -I libft -I includes
LINK = -L src/libft -lft
LIBFT = src/libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -c $(FLAGS) $(addprefix $(SRC_DIR), $(SRCS)) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) -o $(NAME) $(LINK)
	@echo "Compilation done!"
$(LIBFT):
	@make -s -C src/libft
clean: 
	@make -s -C src/libft/ clean
	@rm -rf obj
	@echo ".o removed!"

fclean: clean
	@rm -rf $(NAME)
	@make -s -C src/libft/ fclean
	@echo "$(NAME) removed!"

re: fclean all