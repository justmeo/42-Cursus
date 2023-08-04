/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:14:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/04 17:01:30 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*put(int fd)
// {
// 	char	*split;
// 	char	*me;
// 	size_t	bytesRead;
// 	int i;

// 	i=0;
// 	split = (char *)malloc(BUFFER_SIZE * sizeof(char));
// 	if (!split)
// 		return (NULL);
// 	me = (char *)malloc(BUFFER_SIZE * sizeof(char));
// 	if (!me)
// 		return (NULL);
// 	bytesRead = read(fd, split, BUFFER_SIZE);
// 	if (bytesRead == -1)
// 	{
// 		free(split);
// 		return (NULL);
// 	}
// 	me = ft_strjoin(me,split);
// 	while (me[i] != '\n' && me[i] != '\0')
// 	{
// 		i++;
// 	}
// 	i++;

// 	return (me);
// }

char	*rm_str(char *me)
{
	while (*me != '\n')
	{
		me++;
		if (*me == '\0')
			return (NULL);
	}
	if (*me == '\n')
		me++;
	return (me);
}

char	*get_next_line(int fd)
{
	static char	*me;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (!me)
			me = strdup(buffer);
		else
			me = ft_strjoin(me, buffer);
		if (ft_strchr(me, '\n'))
		{
			line = strdup(me);
			line = opp_strchr(line, '\n');
			me = rm_str(me);
			return (line);
		}
		bytes = 0;
	}
	if (bytes == 0 && me)
	{
		line = strdup(me);
		line = opp_strchr(line, '\n');
		me = rm_str(me);
		// me = NULL;
		return (line);
	}
	return (NULL);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	// Replace "your_file.txt" with the path to the file you want to read
// 	fd = open("test1.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening the file");
// 		return (1);
// 	}
// 	printf("%s$", get_next_line(fd));
// 	printf("%s$", get_next_line(fd));
// 	printf("%s$", get_next_line(fd));
// 	printf("%s$", get_next_line(fd));

// 	// line = get_next_line(fd);
// 	// // printf("%s\n", get_next_line(fd));

// 	// while (line != NULL)
// 	// {
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// }

// 	close(fd);

// 	return (0);
// }