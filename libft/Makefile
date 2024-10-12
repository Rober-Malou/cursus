# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 22:59:15 by robenite          #+#    #+#              #
#    Updated: 2024/10/11 20:46:23 by robenite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= $(addprefix ft_, $(addsuffix .c, atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa memccpy memchr memcmp memcmp memcpy memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd split strchr strchr strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr strrchr strtrim substr tolower toupper))

OBJS := $(SRC:%.c=%.o)

NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

INC_DIR = -I .

CPPFLAGS = -I$(INC_DIR)

RM = rm -f

ARNAME = ar rcs $(NAME)

RANNAME = ranlib $(NAME)

all: $(NAME)

$(NAME): $(OBJS) 
	$(ARNAME) $(OBJS) 
	$(RANNAME)

%.o: %.c
	$(CC) $(INC_DIR) $(CCFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all