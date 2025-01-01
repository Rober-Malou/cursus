SRC	= $(addprefix ft_, $(addsuffix .c, printf printf_utils))

OBJS := $(SRC:%.c=%.o)

NAME = libftprintf.a

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