/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:18:32 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/21 14:05:08 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*rm_str(char *me)
{
	if (!me)
		return (NULL);
	while (*me != '\n')
	{
		if (*me == '\0')
			return (NULL);
		me++;
	}
	if (*me == '\n')
		me++;
	return (me);
}

char	*tired(char *me)
{
	char	*you;

	if (rm_str(me) != NULL)
	{
		you = ft_strdup(rm_str(me));
		free(me);
	}
	else
		return (NULL);
	return (you);
}

char	*something(char **me)
{
	char	*line;

	line = opp_strchr(me, '\n');
	*me = tired(*me);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*me[H1];
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		me[fd] = ft_strjoin(me[fd], buffer);
		if (ft_strchr(me[fd], '\n'))
			return (line = something(&me[fd]));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes == 0 && me[fd])
		return (line = something(&me[fd]));
	if (me[fd])
		free(me[fd]);
	me[fd] = NULL;
	return (me[fd]);
}
