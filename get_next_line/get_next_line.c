/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:52:24 by robenite          #+#    #+#             */
/*   Updated: 2024/11/13 10:41:03 by robenite         ###   ########.fr       */
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
	void			*buf;
	static ssize_t	*bites_read;
	static int		i;
	size_t			o;

	i = 0;
	o = 0;
	buf = malloc(1024);
	if (i == 1024)
	{
		free(buf);
		buf = malloc(1024);
		i = 0;
	}
	if (i == 0)
	{
		bites_read = read(fd, buf, 1023);
		bites_read[1024] = '/0';
	}
	while (bites_read[i] != '/n' && bites_read[i] != '/0')
		o++;
	return (*ft_substr(bites_read, i, o));
}

char	*found(int fd)
{
	looking(fd);
}
