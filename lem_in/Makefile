NAME		= lem-in
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address #-Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits -O3
SRC_FILES	= main.c parsing.c parsing_2.c parsing_3.c parsing_4.c parsing_5.c\
				error_handling.c algorithm.c algorithm_2.c printing.c printing_2.c\
				printing_3.c route_tools.c route_tools_2.c bonus.c
SRCS_DIR	= ./sources/
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS_DIR	= ./objects/
OBJS		= $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
LIB			= -L libft -lft

GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
RED		= "\x1b[31m"
EOC		= "\x1b[0m"

all: $(NAME)
	@echo $(GREEN) "Compiled" $(EOC)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)
	@echo $(RED) "Compiling..." $(EOC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@make -sC libft
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -rf libft/objects/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

