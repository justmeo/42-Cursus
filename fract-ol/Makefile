 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 10:38:18 by ymrabeti          #+#    #+#              #
#    Updated: 2024/01/05 10:37:00 by ymrabeti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRCS = main.c \
mandelbrot.c \
julia.c	\
mvm.c	\
utils.c \
parsing.c \
msg.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

# Minilibx
MLX_PATH	= mlx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

all: $(NAME) $(MLX)

# $(MLX):
# 	@echo "Making MiniLibX..."
# 	@make -sC $(MLX_PATH)
	
# $(NAME): $(OBJS)
# 	@echo "Compiling fractol..."
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)  -lXext -lX11 -lm
# 	@echo "Fractol ready."

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