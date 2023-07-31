char	*get_next_line(int fd)
{
	char *me;
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;
	char *line;

	me = NULL;
	while((bytes_read = read(fd,buffer,BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (me )
		me = ft_strjoin(me,buffer);
		else
		me= strdup(buffer);
		if(strchr(me , '\n'))
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
