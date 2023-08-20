/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 10:53:45 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/20 13:17:14 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*opp_strchr(char **str, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*rm_str(char *me);
char	*no_need(char **str, int i);

#endif
