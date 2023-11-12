# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 10:38:18 by ymrabeti          #+#    #+#              #
#    Updated: 2023/10/30 15:00:08 by ymrabeti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = DESTROYER

SRCS = first.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./mlx
	$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit ./mlx/libmlx.a -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all