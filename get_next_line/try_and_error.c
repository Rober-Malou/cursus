#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*looking(int fd);
char	*found(int fd);

char	*get_next_line(int fd)
{
	char	*next_line;

	if (fd < 0)
		return (NULL);
	next_line = found(fd);
	if (!next_line)
		return (NULL);
	return (next_line);
}

char	*looking(int fd)
{
	static char		*buf = NULL;
	static ssize_t	bytes_read = 0;
	static ssize_t	i = 0;
	char			*chunk;
	char			*new_line;
	size_t			len;

	if (!buf)
	{
		buf = malloc(1024 * sizeof(char));
		if (!buf)
			return (NULL);
	}
	if (i == 0 || i >= bytes_read)
	{
		bytes_read = read(fd, buf, 1023);
		if (bytes_read <= 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[bytes_read] = '\0';
		i = 0;
	}
	chunk = ft_strchr(buf + i, '\n');
	if (chunk)
		len = chunk - (buf + i) + 1; // Include the newline
	else
		len = ft_strlen(buf + i); // No newline, use the remaining buffer
	new_line = ft_substr(buf, i, len);
	i += len; // Move the index forward
	return (new_line);
}

char	*found(int fd)
{
	static char	*left_over = NULL;
	char		*l_read;
	char		*result;

	l_read = looking(fd);
	if (!l_read)
		return (NULL);
	// If there's leftover from the previous call, concatenate it
	if (left_over)
	{
		result = ft_strjoin(left_over, l_read);
		free(left_over);
		left_over = NULL;
		free(l_read);
		if (!result)
			return (NULL);
	}
	else
	{
		result = l_read;
	}
	// Check if the result ends with '\n'; if not, keep it as leftover
	if (result[ft_strlen(result) - 1] != '\n')
	{
		left_over = ft_strdup(result);
		free(result);
		return (NULL);
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*read;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s", "There is no file");
		return (0);
	}
	read = get_next_line(fd);
	printf("primera llamada\n%s", read);
	free(read);
	read = get_next_line(fd);
	printf("segunda llamada\n%s", read);
	free(read);
	read = get_next_line(fd);
	printf("tercera llamada\n%s", read);
	free(read);
	return (0);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	return (0);
	close(fd);
}
