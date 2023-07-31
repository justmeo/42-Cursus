/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymrabeti <ymrabeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:14:27 by ymrabeti          #+#    #+#             */
/*   Updated: 2023/07/31 16:41:07 by ymrabeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*opp_strchr(char *str, int n)
{
	int	i;

	char *me, *start;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != n && str[i])
		i++;
	me = (char *)malloc((i + 1) * sizeof(char));
	if (!me)
		return (NULL);
	start = me;
	while (i > 0 && *str)
	{
		*me++ = *str++;
		i--;
	}
	*me = '\0';
	return (start);
}

static char	*pp(void)
{
	char	*me;

	me = (char *)malloc((1) * sizeof(char));
	me[0] = '\0';
	return (me);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*me;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (pp());
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	me = (char *)malloc((len + 1) * sizeof(char));
	if (!me)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		me[i] = s[start];
		start++;
		i++;
	}
	me[i] = '\0';
	return (me);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*me;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	me = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!me)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		me[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		me[i] = s2[j];
		i++;
		j++;
	}
	me[i] = '\0';
	return (me);
}

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

char	*get_next_line(int fd)
{
	static char	*me;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;

	me = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (me)
			me = ft_strjoin(me, buffer);
		else
			me = strdup(buffer);
		if (strchr(me, '\n'))
		{
			line = strdup(me);
			// free(me);
			// me = strchr(line, '\n') + 1;
			line = opp_strchr(line, '\n');
			return (line);
		}
	}
	if (bytes_read == 0 && me)
	{
		line = strdup(me);
		free(me);
		me = NULL;
		return (line);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*fileName;
// 	int		fd;

// 	fileName = "test1.txt";
// 	fd = open(fileName, O_RDWR);
// 	if (fd == -1)
// 	{
// 		printf("\nError Opening File!!\n");
// 		exit(1);
// 	}
// 	else
// 	{
// 		printf("\nFile %s opened sucessfully!\n", fileName);
// 	}
// 	printf("File Contents: %s\n", get_next_line(fd));
// 	return (0);
// }

int	main(void)
{
	int fd;
	char *line;

	// Replace "your_file.txt" with the path to the file you want to read
	fd = open("test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening the file");
		return (1);
	}
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));

	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// }

	close(fd);

	return (0);
}