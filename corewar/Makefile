# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:19:09 by asuikkan          #+#    #+#              #
#    Updated: 2022/12/07 16:19:11 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		 = gcc
CFLAGS	 = -Wall -Wextra -Werror

NAME_ASM = asm
NAME_VM  = corewar

ASM_DIR  = ./assembler
VM_DIR   = ./vm

VM_SRC	= main.c arguments.c error.c options_champion.c 				\
		  options_text_op.c parse_champion.c champion_id.c				\
		  save_champion.c big_endian_convert.c check_champions.c		\
		  game.c deploy.c byte_reading.c op_add_sub.c					\
		  op_and_or_xor.c op_ld_ldi_lld_lldi.c op_live_aff.c			\
		  op_st_sti.c op_zjmp_fork_lfork.c print_add_sub.c				\
		  print_and_or_xor.c print_live_aff.c print_st_sti.c			\
		  print_ld_ldi_lld_lldi.c print_zjmp_fork_lfork.c				\
		  carriage.c carriage_update.c print_options.c					\
		  game_auxiliaries.c

ASM_SRC	= main.c \
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

VM_SRC_DIR	= ./vm/sources/
ASM_SRC_DIR	= ./assembler/src/

VM_SRCS		= $(addprefix $(VM_SRC_DIR), $(VM_SRC))
ASM_SRCS	= $(addprefix $(ASM_SRC_DIR), $(ASM_SRC))

VM_OBJ_DIR	= ./vm/objects/
ASM_OBJ_DIR	= ./assembler/obj/

VM_OBJS		= $(addprefix $(VM_OBJ_DIR), $(VM_SRC:.c=.o))
ASM_OBJS	= $(addprefix $(ASM_OBJ_DIR), $(ASM_SRC:.c=.o))

VM_INCS		= -I./vm/includes/
ASM_INCS	= -I./assembler/includes
SHR_INC		= -I./libft -I./libft/ft_printf/includes -I./shared/includes

LIB_DIR		= ./libft/
LIB			= -L $(LIB_DIR) -lft

EOC		 = \033[0m
GREEN	 = \033[32m
BLUE	 = \033[34m
SALMON	 = \033[38;5;203m
PURPLE	 = \033[38;5;134m
LGRAY	 = \033[38;5;244m
GOLD 	 = \033[38;5;136m
SILVER	 = \033[38;5;247m
RUST	 = \033[38;5;130m
BLACK	 = \033[38;5;236m
WHITE	 = \033[38;5;231m

all: $(NAME_ASM) $(NAME_VM)
	@echo "$(PURPLE)[asm] $(GREEN)Compiled!$(EOC)"
	@echo "$(BLUE) [vm]$(EOC) $(GREEN)Compiled!$(EOC)"

$(NAME_ASM): $(ASM_OBJS)
	@$(CC) $(CFLGS) $(ASM_OBJS) -o $(NAME_ASM) $(LIB)
	@echo "$(PURPLE)[asm] $(SILVER)Compiling...$(EOC)"

$(NAME_VM): $(VM_OBJS)
	@$(CC) $(CFLAGS) $(VM_OBJS) -o $(NAME_VM) $(LIB)
	@echo "$(BLUE) [vm]$(EOC) $(SILVER)Compiling...$(EOC)"

$(VM_OBJ_DIR)%.o: $(VM_SRC_DIR)%.c
	@make -sC $(LIB_DIR)
	@mkdir -p $(VM_OBJ_DIR)
	@$(CC) $(VM_INCS) $(SHR_INC) -c $(CFLAGS) $< -o $@

$(ASM_OBJ_DIR)%.o: $(ASM_SRC_DIR)%.c
	@make -sC $(LIB_DIR)
	@mkdir -p $(ASM_OBJ_DIR)
	@$(CC) -c $(CFLGS) $< -o $@ $(ASM_INCS) $(SHR_INC)

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(ASM_OBJ_DIR)
	@echo "$(PURPLE)[asm] $(LGRAY)Deleting object directory...$(EOC)"
	@rm -rf $(VM_OBJ_DIR)
	@echo "$(BLUE) [vm] $(LGRAY)Deleting object directory...$(EOC)"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME_ASM)
	@echo "$(PURPLE)[asm]$(EOC) $(LGRAY)Executable $(WHITE)$(NAME_ASM)$(EOC) $(LGRAY)removed!$(EOC)"
	@rm -rf $(NAME_VM)
	@echo "$(BLUE) [vm]$(EOC) $(LGRAY)Executable $(WHITE)$(NAME_VM)$(EOC) $(LGRAY)removed!$(EOC)"

re: fclean all

.PHONY: clean fclean re
