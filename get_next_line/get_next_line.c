/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:52:24 by robenite          #+#    #+#             */
/*   Updated: 2024/11/14 07:33:51 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (fd == -1)
		return (NULL);
	found(fd);
	return (NULL);
}

char	*looking(int fd)
{
	static char			*buf;
	static ssize_t	bytes_read;
	static int		i;
	size_t			o;
	char			*new_line;

	if (!i)
		i = 0;
	if (i == 1024)
	{
		free(buf);
		i = 0;
	}
	if (i == 0)
	{
		buf = malloc(1024);
		if (!buf)
			return (NULL);
		bytes_read = read(fd, buf, 1023);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
	}
	o = (ft_strlen(buf) - ft_strlen(ft_strchr(buf + i, '\n')));
	new_line = ft_substr(buf, i, o);
	i = o + 1;
	return (new_line);
}

char	*found(int fd)
{
	looking(fd);
}
