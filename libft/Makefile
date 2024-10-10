# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 22:59:15 by robenite          #+#    #+#              #
#    Updated: 2024/10/10 23:40:57 by robenite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= $(addprefix ft_, atoi.c bzero.c calloc.c isalnum.c isalpha.c isascii.c isdigit.c isprint.c itoa.c memccpy.c memchr.c memcmp.c memcmp.c memcpy.c memmove.c memset.c putchar_fd.c putendl_fd.c putnbr_fd.c putstr_fd.c split.c strchr.c strchr.c strdup.c striteri.c strjoin.c strlcat.c strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c strrchr.c strtrim.c substr.c tolower.c toupper.c)

OBJS	= $(SRCS: %.c=%.o)

FLAGS	= -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I.
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all