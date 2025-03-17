SRC	= $(addprefix ft_, $(addsuffix .c, atoi bzero calloc isalnum isalpha \
	isascii isdigit isprint itoa memchr memcmp memcpy memmove memset \
	putchar_fd putendl_fd putnbr_fd putstr_fd split	strchr strchr strdup \
	striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr strrchr \
	strtrim substr tolower toupper))

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

BONUS_FLAG = 0

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) 
	$(ARNAME) $(OBJS) 
	$(RANNAME)

bonus: $(NAME) $(BONUS_OBJS)
	@if [ -f .bonus_flag ]; then \
		echo "make: Nothing to be done for 'bonus'"; \
	else \
		$(ARNAME) $(BONUS_OBJS) $(RANNAME);\
		touch .bonus_flag; \
	fi

%.o: %.c
	$(CC) $(INC_DIR) $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) .bonus_flag

re: fclean all