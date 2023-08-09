/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:14:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/08/09 13:57:18 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rm_str(char *me)
{
	while (*me != '\n')
	{
		if (*me == '\0')
		{
			// free(me);
			// me = malloc(1 * sizeof(char));
			// me = NULL;
			return (NULL);
		}
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
		return (rm_str(me));
	return (you);
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
			me = ft_strdup(buffer);
		else
			me = ft_strjoin(me, buffer);
		if (ft_strchr(me, '\n'))
		{
			line = opp_strchr(me, '\n');
			me = tired(me);
			return (line);
		}
	}
	if (bytes == 0 && me)
	{
		line = opp_strchr(me, '\n');
		me = tired(me);
		return (line);
	}
	return (NULL);
}

// char	*get_next_line(int fd)
// {
// 	static char	*me;
// 	char		*you;
// 	char		*them;
// 	char		buffer[BUFFER_SIZE + 1];
// 	int			i;

// 	if (fd < 0)
// 		return (NULL);
// 	if (!me)
// 		me = malloc(BUFFER_SIZE + 1 * sizeof(char));
// 	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		buffer[i] = '\0';
// 		if (ft_strchr(me, '\n'))
// 		{
// 			them = opp_strchr(me, '\n');
// 			me = rm_str(me);
// 			you = malloc((ft_strlen(me) + 1) * sizeof(char));
// 			ft_memcpy(you, me, ft_strlen(you));
// 			free(me);
// 			me = malloc(ft_strlen(you) * sizeof(char));
// 			ft_memcpy(me, you, ft_strlen(you));
// 			return (them);
// 		}
// 		me = ft_strjoin(me, buffer);
// 	}
// 	if (i == 0 && me)
// 	{
// 		them = opp_strchr(me, '\n');
// 		you = malloc(ft_strlen(rm_str(me)) + 1 * sizeof(char));
// 		you = rm_str(me);
// 		free(me);
// 		ft_memcpy(me, you, ft_strlen(you));
// 		return (them);
// 	}
// 	return (NULL);
// }

// char	*get_next_line(int fd)
// {
// 	int		line_size;
// 	char	c;
// 	char	*line;

// 	if (fd < 0)
// 		return (NULL);
// 	line = NULL;
// 	line_size = 0;
// 	while (read(fd, &c, 1) > 0)
// 	{
// 		if (line_size % BUFFER_SIZE == 0)
// 			line = realloc(line, (line_size + BUFFER_SIZE) * sizeof(char));
// 		line[line_size++] = c;
// 		if (c == '\n')
// 			break ;
// 	}
// 	if (line_size == 0)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	line[line_size] = '\0';
// 	return (line);
// }

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
// 	// printf("%s$", get_next_line(fd));
// 	// printf("%s$", get_next_line(fd));
// 	// printf("%s$", get_next_line(fd));
// 	// printf("%s$", get_next_line(fd));

// 	line = get_next_line(fd);
// 	// printf("%s\n", get_next_line(fd));

// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}

// 	close(fd);

// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char *me;
// 	char *you;
// 	char *line;
// 	char buffer[BUFFER_SIZE + 1];
// 	int bytes;
// 	size_t i;
// 	size_t j;
// 	size_t k;
// 	size_t a;
// 	size_t b;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);

// 	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		i = j = k = a = b = 0;
// 		buffer[bytes] = '\0';
// 		if (!me)
// 		{
// 			me = malloc(ft_strlen(buffer) * sizeof(char));
// 			while (buffer[i])
// 			{
// 				me[i] = buffer[i];
// 				i++;
// 			}
// 		}
// 		else
// 		{
// 			you = malloc((ft_strlen(me) + 1) * sizeof(char));
// 			while (me[i])
// 			{
// 				you[i] = me[i];
// 				i++;
// 			}
// 			free(me);
// 			me = malloc((ft_strlen(you) + ft_strlen(buffer) + 1)
// 					* sizeof(char));
// 			while (you[j])
// 			{
// 				me[j] = you[j];
// 				j++;
// 			}
// 			free(you);
// 			while (buffer[j])
// 				me[j++] = buffer[k++];
// 			me[j] = '\0';
// 		}
// 		while (strchr(me, '\n'))
// 		{
// 			while (me[a] != '\n')
// 				a++;
// 			line = malloc((a + 1) * sizeof(char));
// 			a = 0;
// 			while (me[a] != '\n')
// 			{
// 				line[a] = me[a];
// 				a++;
// 			}
// 			line[a] = '\0';
// 			b = a;
// 			while (me[a] != '\0')
// 				a++;
// 			you = malloc(a * sizeof(char));
// 			a = 0;
// 			while (me[b] != '\0')
// 				you[a++] = me[b++];
// 			you[a] = '\0';
// 			free(me);
// 			b = 0;
// 			me = malloc(a * sizeof(char));
// 			while (you[b] != '\0')
// 			{
// 				me[b] = you[b];
// 				b++;
// 			}
// 			free(you);
// 			return (line);
// 		}
// 	}
// 	if (bytes == 0 && me)
// 	{
// 		while (me[a] != '\0')
// 			a++;
// 		line = malloc((a + 1) * sizeof(char));
// 		a = 0;
// 		while (me[a] != '\0')
// 		{
// 			line[a] = me[a];
// 			a++;
// 		}
// 		line[a] = '\0';
// 		b = a;
// 		while (me[a] != '\0')
// 			a++;
// 		you = malloc(a * sizeof(char));
// 		a = 0;
// 		while (me[b] != '\0')
// 			you[a++] = me[b++];
// 		you[a] = '\0';
// 		free(me);
// 		b = 0;
// 		me = malloc(a * sizeof(char));
// 		while (you[b] != '\0')
// 		{
// 			me[b] = you[b];
// 			b++;
// 		}
// 		free(you);
// 		return (line);
// 	}
// 	return (NULL);
// }