SRC	= $(addsuffix .c, main set_colum cheks)

OBJS := $(SRC:%.c=%.o)

BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC_DIR = -I .

RM = rm -f

LIB = ./libft/libft.a

all: $(NAME)

$(LIB):
	make -C ./libft

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(INC_DIR) $(CFLAGS) -o $@ -c $<

.PHONY: all fclean clean re

clean: 
	$(RM) $(OBJS)
	make -C ./libft/ clean

fclean: clean
		$(RM) $(NAME)
		make -C ./libft/ fclean

re: fclean all