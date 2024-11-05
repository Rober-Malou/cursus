/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main .c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 04:16:39 by robenite          #+#    #+#             */
/*   Updated: 2024/11/05 05:26:45 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	buf;

	fd = open(argv[1], O_RDONLY);
	buf = *get_next_line(fd);
	printf("%s\n", buf);
	close(fd);
	free(buf);
	return (0);
}
