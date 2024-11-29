/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:52:24 by robenite          #+#    #+#             */
/*   Updated: 2024/11/29 06:11:07 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_going_free(char **object);
char	*looking(int fd);
char	*found(int fd);
int		main(int argc, char *argv[]);

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
	static char			*buf;
	static ssize_t	bytes_read;
	static int		i;
	size_t			o;
	char			*new_line;
	char			*chunk;

	if (!i)
		i = 0;
	if (!buf)
	{
		buf = malloc(1024 * sizeof(char));
		if (!buf)
			return (ft_going_free(&buf));
	}
	if (i == 0 || i >= bytes_read)
	{
		bytes_read = read(fd, buf, 1023);
		if (bytes_read == 0)
			return (ft_going_free(&buf));
		else if(bytes_read < 0)
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
        			result = ft_strjoin(left_over, l_read);
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
	printf("primera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("segunda llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	free(read);
	read = NULL;
	close(fd);
	return (0);
}
