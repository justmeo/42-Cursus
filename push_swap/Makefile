CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/mvm/pa.c\
srcs/mvm/pb.c\
srcs/mvm/ra.c\
srcs/mvm/rb.c\
srcs/mvm/rra.c\
srcs/mvm/sa.c\
srcs/mvm/sb.c\
srcs/push_swap.c \
srcs/ft_split.c \
srcs/ft_atoll.c  \
srcs/sort.c \
srcs/utils.c \
srcs/push_swap_utils.c \
srcs/utils_2.c

FT_PRINTF = ft_printf.a
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(FT_PRINTF)

$(FT_PRINTF):
	make -C ./ft_printf

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./ft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	make clean -C ./ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ./ft_printf

re: fclean all