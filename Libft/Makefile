CC = gcc
rm = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c \
ft_split.c ft_strchr.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

Objs = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(Objs)
	ar rc $(NAME) $(Objs)
	ranlib $(NAME)

clean:
	$(rm) $(Objs)

fclean: clean
	$(rm) $(NAME)

re: fclean all

.PHONY: all clean fclean re