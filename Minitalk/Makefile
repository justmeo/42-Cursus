# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 13:43:59 by ymrabeti          #+#    #+#              #
#    Updated: 2024/05/27 14:51:26 by ymrabeti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

FT_PRINTF = ft_printf.a

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	make -C ./ft_printf

$(SERVER): $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER) -L./ft_printf -lftprintf

$(CLIENT): $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT) -L./ft_printf -lftprintf

clean:
	rm -f $(SERVER) $(CLIENT)
	make clean -C ./ft_printf

re: clean all
