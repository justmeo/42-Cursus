CC = cc

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g

SRCS = init.c \
utils.c \
philo.c 

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