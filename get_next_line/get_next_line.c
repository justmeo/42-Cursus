/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:14:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2024/07/18 16:34:00 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*me;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		me = ft_strjoin(me, buffer);
		if (ft_strchr(me, '\n'))
			return (line = something(&me));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes == 0 && me)
		return (line = something(&me));
	if (me)
		free(me);
	me = NULL;
	return (me);
}

int	main(void)
{
	int		fd;
	char	*line;

	// Replace "your_file.txt" with the path to the file you want to read
	fd = open("test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening the file");
		return (1);
	}
	printf("%s$", get_next_line(fd));
	printf("%s$", get_next_line(fd));
	printf("%s$", get_next_line(fd));
	printf("%s$", get_next_line(fd));
	// line = get_next_line(fd);
	// printf("%s\n", get_next_line(fd));
	// while (line != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	close(fd);
	return (0);
}