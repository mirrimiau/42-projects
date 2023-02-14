# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 14:15:24 by altikka           #+#    #+#              #
#    Updated: 2022/12/06 13:58:03 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= asm

CC			= gcc

CFLGS		= -Wall -Wextra -Werror

INCS		= -I./includes -I../libft -I../libft/ft_printf/includes -I../shared/includes

SRC_FILES	= main.c \
			  main_utils.c \
			  parse.c \
			  options.c \
			  debug.c \
			  init.c \
			  lex.c \
			  lex_bools.c \
			  lex_utils.c \
			  lex_tokenization.c \
			  lex_endof.c \
			  lex_comment.c \
			  lex_header.c \
			  lex_command.c \
			  lex_argument.c \
			  lex_label.c \
			  lex_label_fill.c \
			  lex_comma.c \
			  lex_check_labels.c \
			  source_read.c \
			  source_utils.c \
			  cleanup.c \
			  cleanup_source.c \
			  cleanup_lex.c \
			  assemble.c \
			  write_file.c \
			  write_header.c \
			  write_bytecode.c \
			  write_utils.c

SRC_DIR		= ./src/
SRCS		= $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJ_DIR		= ./obj/
OBJS		= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

LIB_DIR		= ../libft/
LIB			= -L $(LIB_DIR) -lft

EOC = \033[0m
GREEN = \033[38;5;70m
YELLOW = \033[38;5;220m
PURPLE = \033[38;5;134m
LGRAY = \033[38;5;244m
GOLD = \033[38;5;136m
SILVER = \033[38;5;247m
RUST = \033[38;5;130m

all: $(NAME)
	@echo "$(PURPLE)[asm] $(GREEN)Compiled!$(EOC)"

$(NAME): $(OBJS)
	@$(CC) $(CFLGS) $(OBJS) -o $(NAME) $(LIB) $(INCS)
	@echo "$(PURPLE)[asm] $(SILVER)Compiling...$(EOC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@make -sC $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLGS) $< -o $@ $(INCS)

clean:
	@make -sC $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(PURPLE)[asm] $(LGRAY)Deleting object directory...$(EOC)"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)
	@echo "$(PURPLE)[asm] $(LGRAY)Executable $(WHITE)$(NAME)$(EOC) $(LGRAY)removed!$(EOC)"

re: fclean all

.PHONY: all clean fclean re
