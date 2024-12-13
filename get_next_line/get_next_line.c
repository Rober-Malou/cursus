/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:52:24 by robenite          #+#    #+#             */
/*   Updated: 2024/12/13 06:25:23 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*going_free(char **object);
char	*looking(int fd, char **buf, ssize_t *bytes_read, int *i);
char	*found(int fd, char **buf, ssize_t *bytes_read, int *i);
char	*merge_line(char *i_line, int fd, char **buf, ssize_t *bytes_read,
			int *i);

char	*get_next_line(int fd)
{
	char			*next_line;
	static char		*buf = NULL;
	static ssize_t	bytes_read = 0;
	static int		i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = found(fd, &buf, &bytes_read, &i);
	if (!next_line)
		return (NULL);
	return (next_line);
}

char	*looking(int fd, char **buf, ssize_t *bytes_read, int *i)
{
	size_t	o;
	char	*new_line;
	char	*chunk;

	if (*i == 0 || *i >= *bytes_read)
	{
		*bytes_read = read(fd, *buf, BUFFER_SIZE - 1);
		if (*bytes_read <= 0)
			return (going_free(buf));
		(*buf)[*bytes_read] = '\0';
		*i = 0;
	}
	chunk = ft_strchr(*buf + *i, '\n');
	if (chunk)
		o = chunk - (*buf + *i) + 1;
	else
		o = ft_strlen(*buf + *i);
	new_line = ft_substr(*buf, *i, o);
	if (!new_line)
		return (NULL);
	*i += o;
	return (new_line);
}

char	*found(int fd, char **buf, ssize_t *bytes_read, int *i)
{
	char	*l_read;
	char	*result;

	if (!*buf)
	{
		*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!*buf)
			return (NULL);
		*bytes_read = 0;
		*i = 0;
	}
	l_read = looking(fd, buf, bytes_read, i);
	if (!l_read)
		return (NULL);
	if (l_read[ft_strlen(l_read) - 1] == '\n')
		return (l_read);
	result = merge_line(l_read, fd, buf, bytes_read, i);
	return (result);
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

char	*merge_line(char *i_line, int fd, char **buf, ssize_t *bytes_read,
		int *i)
{
	static char	*left_over = NULL;
	char		*m_line;
	char		*temp;

	m_line = NULL;
	if (!left_over)
	{
		left_over = ft_strdup(i_line);
		going_free(&i_line);
		if (!left_over)
			return (NULL);
	}
	else
	{
		m_line = ft_strjoin(left_over, i_line);
		going_free(&left_over);
		going_free(&i_line);
		if (!m_line)
			return (NULL);
		while (m_line && m_line[ft_strlen(m_line) - 1] != '\n')
		{
			left_over = ft_strdup(m_line);
			going_free(&m_line);
			i_line = looking(fd, buf, bytes_read, i);
			if (!i_line)
				return (left_over);
			temp = ft_strjoin(left_over, i_line);
			going_free(&left_over);
			going_free(&i_line);
			m_line = temp;
			if (!m_line)
				return (NULL);
		}
	}
	return (m_line);
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
