
#include "get_next_line.h"

char	*opp_strchr(char *str, int n)
{
	char *me, *start;
	int i;
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
int main()
{
    char s[20]="yas yas yasf fj";
    printf("%s\n",opp_strchr(s,' '));
}

char	*get_next_line(int fd)
{
	static char	*me;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	me = NULL;
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
			free(me);
			me = strchr(line, '\n') + 1;
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