#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*opp_strchr(char *str, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

#endif