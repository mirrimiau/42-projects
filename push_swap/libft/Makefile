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
 
FTFUNCTIONS = strlen strdup strcpy strncpy strcat strncat strlcat strchr \
	strrchr strstr strnstr strcmp strncmp isdigit atoi isalpha isalnum \
	isascii isprint toupper tolower memset bzero memcpy memccpy memmove \
	memchr memcmp memalloc memdel strnew strdel strclr striter striteri \
	strmap strmapi strequ strnequ strsub strjoin strtrim strsplit itoa \
	putchar_fd putstr_fd putendl_fd putnbr_fd putchar putstr putendl \
	putnbr lstnew lstdelone lstdel lstadd lstiter lstmap strcasestr calloc \
	strrev isspace

FUNCTIONS = $(patsubst %, ft_%, $(FTFUNCTIONS)) ft_printf typetostr \
	attributes attributes_2 attributes_3 width width_2 precision flags \
	flags_2 specifiers specifiers_2 specifiers_3 length get_next_line

INCLUDES = libft.h ft_printf.h
OFILES = $(patsubst %, %.o, $(FUNCTIONS))
CFILES = $(patsubst %, %.c, $(FUNCTIONS))

.PHONY: clean fclean re all

all: $(NAME)

$(NAME):
	gcc  $(CFILES) -Wall -Wextra -Werror -c -I $(INCLUDES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
