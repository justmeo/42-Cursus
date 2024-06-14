

CC = cc

NAME = pushswap

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/push_swap.c \
srcs/ft_split.c \
srcs/ft_atoll.c  \
srcs/mvm.c	\
srcs/sort.c




OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all