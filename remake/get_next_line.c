/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:40:31 by robenite          #+#    #+#             */
/*   Updated: 2024/12/16 06:48:33 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*next_line;
	static char		*buf = NULL;
	static ssize_t	*bytes_read = 0;
	static int		*i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf == NULL)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		bytes_read = 0;
		i = 0;
	}
	next_line = check_line(fd, buf, bytes_read, i);
	while (next_line[ft_strlen(next_line) - 1] != '\n')
	{
		next_line = join_pieces(next_line);
	}
	if (!next_line)
		return (NULL);
	return (next_line);
}

char	*check_line(int fd, char *buf, ssize_t *bytes_read, int *i)
{
	size_t	o;
	char	*new_line;
	char	*chunk;

	if (*i == 0 || *i >= *bytes_read)
	{
		*bytes_read = read(fd, buf, BUFFER_SIZE - 1);
		if (*bytes_read <= 0)
			return (going_free(&buf));
		(buf)[*bytes_read] = '\0';
		*i = 0;
	}
	chunk = ft_strchr(buf + *i, '\n');
	if (chunk)
		o = chunk - (buf + *i) + 1;
	else
		o = ft_strlen(buf + *i);
	new_line = ft_substr(buf, *i, o);
	if (!new_line)
		return (NULL);
	*i += o;
	return (new_line);
}

char	*join_pieces(char *piece_of_line)
{
	static char	*left_over = NULL;
	char		*temp;

	if (left_over != NULL)
	{
		temp = ft_strjoin(left_over, piece_of_line);
		going_free(&left_over);
		going_free(&piece_of_line);
		left_over = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	else
	{
		left_over = ft_strdup(piece_of_line);
		going_free(&piece_of_line);
	}
	return (left_over);
}

char	*going_free(char **object)
{
	if (object && *object)
	{
		free(*object);
		*object = NULL;
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("el_quijote.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		going_free(&line);
	}
	close(fd);
	return (0);
}
