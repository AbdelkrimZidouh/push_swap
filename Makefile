NAME = push_swap

SRC = push_swap.c stack_init.c stack_utils.c ft_split.c utils.c 
 
SOBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER = push_swap.h

all : $(NAME)

$(NAME) : $(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) -o $(NAME)


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(SOBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re