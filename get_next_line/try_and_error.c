/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_and_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:57:01 by robenite          #+#    #+#             */
/*   Updated: 2024/12/06 01:14:51 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char	*ft_going_free(char **object)
{
	if (object && *object)
	{
		free(*object);
		*object = NULL;
	}
	return (NULL);
}

char	*extract_line(char *buf, size_t *i, ssize_t bytes_read)
{
	char	*chunk;
	char	*new_line;
	size_t	o;

	chunk = ft_strchr(buf + *i, '\n');
	if (chunk)
		o = chunk - (buf + *i) + 1;
	else
		o = ft_strlen(buf + *i);
	new_line = ft_substr(buf, *i, o);
	if (!new_line)
		return (NULL);
	*i += o;
	if (*i >= (size_t)bytes_read)
		*i = 0;
	return (new_line);
}

char	*looking(int fd)
{
	static char		*buf = NULL;
	static ssize_t	bytes_read = 0;
	static size_t	i = 0;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(1024 * sizeof(char));
		if (!buf)
			return (ft_going_free(&buf));
	}
	if (i == 0 || i >= (size_t)bytes_read)
	{
		bytes_read = read(fd, buf, 1023);
		if (bytes_read <= 0)
			return (ft_going_free(&buf));
		buf[bytes_read] = '\0';
		i = 0;
	}
	new_line = extract_line(buf, &i, bytes_read);
	if (!new_line)
		return (ft_going_free(&buf));
	return (new_line);
}

char	*found(int fd)
{
	static char	*left_over = NULL;
	char		*l_read;
	char		*result;

	l_read = looking(fd);
	if (!l_read)
		return (ft_going_free(&l_read));
	if (l_read[ft_strlen(l_read) - 1] != '\n')
	{
		result = ft_strjoin(left_over, l_read);
		if (!result)
			return (ft_going_free(&result));
		free(left_over);
		left_over = result;
		return (NULL);
	}
	result = ft_strjoin(left_over, l_read);
	free(left_over);
	left_over = NULL;
	free(l_read);
	return (result);
}

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

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    if (close(fd) < 0)
    {
        perror("Error closing file");
        return (1);
    }
    return (0);
}

