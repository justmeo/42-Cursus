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
