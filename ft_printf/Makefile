# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 11:10:15 by ymrabeti          #+#    #+#              #
#    Updated: 2023/08/13 11:39:39 by ymrabeti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = printf.all

RM= rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
# ft_putnbr_base.c \
ft_puthex_low.c \
ft_puthex_up.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all