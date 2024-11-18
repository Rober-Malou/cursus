/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:52:24 by robenite          #+#    #+#             */
/*   Updated: 2024/11/17 22:21:30 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*buf;
	static ssize_t	bytes_read;
	static int		i;
	size_t			o;
	char			*new_line;
	char	*chunk;

	if (!i)
		i = 0;
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
		printf("bufer \n %s", buf);
	}
	chunk = ft_strchr(buf + i, '\n');
	printf("chunk \n %s", chunk);
	o = (ft_strlen(buf) - ft_strlen(chunk));
	new_line = ft_substr(buf, i, o);
	printf("lo que devuelve \n %s", new_line);
	i = i + o + 1;
	return (new_line);
}

char	*found(int fd)
{
	char		*l_read;
	int			l_read_len;
	static char	*left_over;

	l_read = looking(fd);
	printf("%s", l_read);
	l_read_len = ft_strlen(l_read);
	if (l_read[l_read_len] != '\n')
	{
		left_over = l_read;
		l_read = ft_strjoin(left_over, l_read);
		return (l_read);
	}
	return (l_read);
}
