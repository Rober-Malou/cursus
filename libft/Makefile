# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 22:59:15 by robenite          #+#    #+#              #
#    Updated: 2024/10/31 02:37:24 by robenite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= $(addprefix ft_, $(addsuffix .c, atoi bzero calloc isalnum isalpha \
	isascii isdigit isprint itoa memchr memcmp memcmp memcpy \
	memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd split strchr \
	strchr strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp \
	strnstr strrchr strtrim substr tolower toupper))

BONUS_SRC= $(addprefix ft_, $(addsuffix _bonus.c, lstnew lstadd_front lstsize \
	lstlast lstadd_back lstdelone lstclear lstiter lstmap))

OBJS := $(SRC:%.c=%.o)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC_DIR = -I .

RM = rm -f

ARNAME = ar rcs $(NAME)

RANNAME = ranlib $(NAME)

BONUS_FLAG = 0

all: $(NAME)

$(NAME): $(OBJS) 
	$(ARNAME) $(OBJS) 
	$(RANNAME)

bonus: $(OBJS) $(BONUS_OBJS)
	$(ARNAME) $(OBJS) $(BONUS_OBJS)
	$(RANNAME) 

%.o: %.c
	$(CC) $(INC_DIR) $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all