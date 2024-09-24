

#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif




	// bytes = read(fd, buffer, BUFFER_SIZE);

char	*get_next_line(int fd)
{
	char *line;
	int	things_read;
	int	position;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	position = -1;
	things_read = -1;
	line = malloc(10000 * sizeof(char));

	while ((things_read != 0 || things_read == -1) && line[position] != '\n')
	{
		position++;
		things_read = read(fd, &line[position] ,BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	if(things_read == 0 && position == 0)
		return (free(line),NULL);
	line[++position] = '\0';
	return (line);
}






int	main(void)
{
	int		fd;
	// char	*line;

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
	// printf("%s", get_next_line(fd));
	// while (line != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	close(fd);
	return (0);
}

#include <unistd.h>
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif


// char	*get_next_line(int fd)
// {
// 	char *line;
// 	int	things_read;
// 	int	position;


// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	position = -1;
// 	things_read = -1;
// 	line = malloc(10000 * sizeof(char));

// 	while ((things_read != 0 || things_read == -1) && line[position] != '\n')
// 	{
// 		position++;
// 		things_read = read(fd, &line[position] ,BUFFER_SIZE - BUFFER_SIZE + 1);
// 	}
// 	if(things_read == 0 && position == 0)
// 		return (free(line),NULL);
// 	line[++position] = '\0';
// 	return (line);
// }