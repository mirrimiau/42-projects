# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:20:00 by asuikkan          #+#    #+#              #
#    Updated: 2022/10/20 16:20:02 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= corewar
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
SRC_FILES	= main.c arguments.c error.c options_champion.c 			\
			  options_text_op.c parse_champion.c champion_id.c			\
			  save_champion.c big_endian_convert.c check_champions.c	\
			  game.c deploy.c byte_reading.c op_add_sub.c				\
			  op_and_or_xor.c op_ld_ldi_lld_lldi.c op_live_aff.c		\
			  op_st_sti.c op_zjmp_fork_lfork.c print_add_sub.c			\
			  print_and_or_xor.c print_live_aff.c print_st_sti.c		\
			  print_ld_ldi_lld_lldi.c print_zjmp_fork_lfork.c			\
			  carriage.c carriage_update.c print_options.c				\
			  game_auxiliaries.c
SRCS_DIR	= ./sources/
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS_DIR	= ./objects/
OBJS		= $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
INC_DIR		= ./includes/
SHR_INC		= ../shared/includes/
LIB_DIR		= ../libft
LIB			= -L $(LIB_DIR) -lft
PRINTF_INC	= ../libft/ft_printf/includes

LGRAY   = \033[38;5;244m
RUST    = \033[38;5;130m
GREEN	= \033[38;5;70m
GOLD	= \033[38;5;136m
YELLOW	= \033[38;5;220m
SILVER	= \033[38;5;247m
BLUE	= \033[34m
RED		= \033[31m
EOC		= \033[0m

all: $(NAME)
	@echo "$(BLUE) [vm]$(EOC) $(GREEN)Compiled!$(EOC)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)
	@echo "$(BLUE) [vm]$(EOC) $(SILVER)Compiling...$(EOC)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@make -sC $(LIB_DIR)
	@mkdir -p $(OBJS_DIR)
	@$(CC) -I $(INC_DIR) -I $(LIB_DIR) -I $(PRINTF_INC) -I $(SHR_INC) -c $(CFLAGS) $< -o $@

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJS_DIR)
	@echo "$(BLUE) [vm] $(LGRAY)Deleting object directory...$(EOC)"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)/libft.a

re: fclean all
