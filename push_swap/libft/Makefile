SRC	= $(addsuffix .c, get_next_line) $(addprefix ft_, $(addsuffix .c, atoi \
	bzero calloc isalnum isalpha isascii isdigit isprint itoa memchr memcmp \
	memcmp memcpy memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd \
	split strchr strchr strdup striteri strjoin strlcat strlcpy strlen \
	strmapi strncmp strnstr strrchr strtrim substr tolower toupper lstnew \
	lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter \
	lstmap printf printf_utils))

OBJS := $(SRC:%.c=%.o)

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC_DIR = -I .

RM = rm -f

ARNAME = ar rcs $(NAME)

RANNAME = ranlib $(NAME)

all: $(NAME)

$(NAME): $(OBJS) 
	$(ARNAME) $(OBJS) 
	$(RANNAME)

%.o: %.c
	$(CC) $(INC_DIR) $(CFLAGS) -o $@ -c $<

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all