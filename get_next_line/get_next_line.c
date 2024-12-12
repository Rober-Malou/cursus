/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malou <malou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:52:24 by robenite          #+#    #+#             */
/*   Updated: 2024/12/11 20:09:09 by malou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#

char	*ft_going_free(char **object);
char	*looking(int fd);
char	*found(int fd);
//int		main(int argc, char *argv[]);

char	*get_next_line(int fd)
{
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
	char			*chunk;

	if (!i)
		i = 0;
	if (!buf)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (ft_going_free(&buf));
	}
	if (i == 0 || i >= bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			return (ft_going_free(&buf));
		else if (bytes_read < 0)
			return (ft_going_free(&buf));
		else
			buf[bytes_read] = '\0';
		i = 0;
		// printf("bufer \n %s", buf);
	}
	chunk = ft_strchr(buf + i, '\n');
	// printf("print i %d", i);
	// printf("chunk \n %s", chunk);
	if (chunk)
		o = chunk - (buf + i) + 1;
	else
		o = ft_strlen(buf + i);
	new_line = ft_substr(buf, i, o);
	if (!new_line)
		return (ft_going_free(&new_line));
	// printf("lo que devuelve \n %s", new_line);
	i += o;
	return (new_line);
}

char	*found(int fd)
{
	char		*l_read;
	static char	*left_over;
	char		*result;

	l_read = looking(fd);
	if (!l_read)
		return (ft_going_free(&l_read));
	// printf("lo que devuelve found %s", l_read);
	if (l_read[ft_strlen(l_read) - 1] != '\n')
	{
		if (!left_over)
		{
			left_over = ft_strdup(l_read);
			if (!left_over)
				return (ft_going_free(&left_over));
		}
		else
		{
			result = ft_strjoin(left_over, l_read);
			if (!result)
				return (ft_going_free(&result));
			while (result && result[ft_strlen(result) - 1] != '\n')
			{
				left_over = ft_strdup(result);
				ft_going_free(&result);
				l_read = looking(fd);
				if (l_read)
				{
					result = ft_strjoin(left_over, l_read);
					//ft_going_free(&l_read);
				}
			}
		}
		free(left_over);
		left_over = NULL;
		return (result);
	}
	return (l_read);
}

char	*ft_going_free(char **object)
{
	if (object && *object)
	{
		free(*object);
		*object = NULL;
	}
	return (NULL);
}


int main(void)
{
	int fd;
	char *line;
	fd = open("el_quijote.txt", O_RDONLY);
	if(fd < 0)
		printf("error al abrir el archivo");
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}
