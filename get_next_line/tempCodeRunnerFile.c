#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *str;
	static char *me;
	char *you;
	char *line;
	char *buffer[BUFFER_SIZE + 1];
	int bytes;
	size_t i;
	size_t j;
	size_t k;
	size_t a;
	size_t b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = j = k = a = b = 0;
		buffer[bytes] = '\0';
		if (!me)
		{
			me = malloc(ft_strlen(buffer) * sizeof(char));
			while (buffer[i])
			{
				me[i] = buffer[i];
				i++;
			}
		}
		else
		{
			you = malloc((ft_strlen(me) + 1) * sizeof(char));
			while (me[i])
			{
				you[i] = me[i];
				i++;
			}
			free(me);
			me = malloc((ft_strlen(you) + ft_strlen(buffer) + 1)
					* sizeof(char));
			while (you[j])
			{
				me[j] = you[j];
				j++;
			}
			free(you);
			while (buffer[j])
				me[j++] = buffer[k++];
			me[j] = '\0';
		}
		while (strchr(me, '\n'))
		{
			while (me[a] != '\n')
				a++;
			line = malloc((a + 1) * sizeof(char));
			a = 0;
			while (me[a] != '\n')
			{
				line[a] = me[a];
				a++;
			}
			line[a] = '\0';
			b = a;
			while (me[a] != '\0')
				a++;
			you = malloc(a * sizeof(char));
			a = 0;
			while (me[b] != '\0')
				you[a++] = me[b++];
			you[a] = '\0';
			free(me);
			b = 0;
			me = malloc(a * sizeof(char));
			while (you[b] != '\0')
			{
				me[b] = you[b];
				b++;
			}
			free(you);
			return (line);
		}
	}
	if (bytes == 0 && me)
	{
		while (me[a] != '\0')
			a++;
		line = malloc((a + 1) * sizeof(char));
		a = 0;
		while (me[a] != '\0')
		{
			line[a] = me[a];
			a++;
		}
		line[a] = '\0';
		b = a;
		while (me[a] != '\0')
			a++;
		you = malloc(a * sizeof(char));
		a = 0;
		while (me[b] != '\0')
			you[a++] = me[b++];
		you[a] = '\0';
		free(me);
		b = 0;
		me = malloc(a * sizeof(char));
		while (you[b] != '\0')
		{
			me[b] = you[b];
			b++;
		}
		free(you);
		return (line);
	}
}

static char	*ft_restbuffer(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	rest = (char *) malloc ((ft_strlen(buffer)) - i + 1 * sizeof(char));
	if (!rest)
		return (NULL);
	if (buffer[i] && buffer[i] == '\n')
	{
		i++;
		while (buffer[i])
			rest[j++] = buffer[i++];
		rest[j] = '\0';
	}
	free (buffer);
	return (rest);
}

static char	*ft_getrow(char *buffer)
{
	char	*row;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		row = (char *) malloc (i + 2 * sizeof(char));
	else
		row = (char *) malloc (i + 1 * sizeof(char));
	if (!row)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		row[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		row[i] = buffer[i];
		i++;
	}
	row[i] = '\0';
	return (row);
}

static char	*ft_readit(int fd, char *buffer)
{
	char	*row;
	int		i;

	row = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!row)
		return (NULL);
	i = 1;
	while (!ft_strchr(buffer, '\n') && i > 0)
	{
		i = read(fd, row, BUFFER_SIZE);
		if (i == -1)
		{
			free (row);
			if (buffer)
				free (buffer);
			return (NULL);
		}
		row[i] = '\0';
		buffer = ft_strjoin(buffer, row);
	}
	free (row);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*row;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readit(fd, buffer);
	if (!buffer)
		return (NULL);
	row = ft_getrow(buffer);
	buffer = ft_restbuffer(buffer);
	return (row);
}

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

char	*ft_strchr(const char *s, int c )
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free (s1);
	return (str);
}