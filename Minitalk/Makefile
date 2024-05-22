# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 13:43:59 by ymrabeti          #+#    #+#              #
#    Updated: 2024/05/22 14:20:38 by ymrabeti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

all: $(SERVER) $(CLIENT)

$(SERVER): 
	$(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER)

$(CLIENT): 
	$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT)

clean:
	rm -f $(SERVER) $(CLIENT)

re: clean all
