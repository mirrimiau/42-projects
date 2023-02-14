NAME = ft_display_file
INCLUDES = includes.h
FUNCTIONS = main
CFILES = $(patsubst %, %.c, $(FUNCTIONS))

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -o $(NAME) $(CFILES) 

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all 