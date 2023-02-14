# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapostol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 19:53:47 by mapostol          #+#    #+#              #
#    Updated: 2021/11/19 15:45:56 by mapostol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
FTFUNCTIONS = strlen strdup strcpy strncpy strcat strncat strlcat strchr \
	strrchr strstr strnstr strcmp strncmp isdigit atoi isalpha isalnum \
	isascii isprint toupper tolower memset bzero memcpy memccpy memmove \
	memchr memcmp memalloc memdel strnew strdel strclr striter striteri \
	strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa \
	putchar_fd putstr_fd putendl_fd putnbr_fd putchar putstr putendl \
	putnbr lstnew lstdelone lstdel lstadd lstiter lstmap strcasestr calloc \
	strrev isspace strupdate

SRCS = $(patsubst %, ft_%.c, $(FTFUNCTIONS)) ft_printf.c typetostr.c \
	attributes.c attributes_2.c attributes_3.c width.c width_2.c precision.c \
	flags.c	flags_2.c specifiers.c specifiers_2.c specifiers_3.c length.c \
	get_next_line.c
SRCS_DIR = ./sources/
OBJS = $(addprefix	$(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR = ./objects/

BLUE	= "\x1b[34m"

all: $(NAME)
	
$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo $(BLUE) "Compiling libft..." $(EOC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<
	
clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re