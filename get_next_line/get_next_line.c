/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:40:31 by robenite          #+#    #+#             */
/*   Updated: 2025/01/20 19:27:54 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fech_next_line(int fd, char *leftover, char *buffer);
static char	*_cuting_line(char *piece_of_text);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(leftover);
		free(buffer);
		leftover = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fech_next_line(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover = _cuting_line(line);
	return (line);
}

static char	*fech_next_line(int fd, char *leftover, char *buffer)
{
	ssize_t	t_read;
	char	*temp;

	t_read = 1;
	while (t_read > 0)
	{
		t_read = read(fd, buffer, BUFFER_SIZE);
		if (t_read == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (t_read == 0)
			break ;
		buffer[t_read] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

static char	*_cuting_line(char *piece_of_text)
{
	char	*leftover;
	ssize_t	i;

	i = 0;
	while (piece_of_text[i] != '\n' && piece_of_text[i] != '\0')
		i++;
	if (piece_of_text[i] == '\0' || piece_of_text[1] == '\0')
		return (NULL);
	leftover = ft_substr(piece_of_text, i + 1, ft_strlen(piece_of_text) - i);
	if (*leftover == 0)
	{
		free(leftover);
		leftover = NULL;
	}
	piece_of_text[i + 1] = 0;
	return (leftover);
}
#include <stdio.h>

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
		free (line);
		line = NULL;
	}
	close(fd);
	return (0);
}
