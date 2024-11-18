/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 04:16:39 by robenite          #+#    #+#             */
/*   Updated: 2024/11/17 22:29:37 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	fd;
	char *read;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s", "There is no file");
		return (0);
	}
	read = get_next_line(fd);
	printf("primera llamada \n %s", read);
	read = get_next_line(fd);
	printf("segunda llamada \n %s", read);
	read = get_next_line(fd);
	printf("tercera llamada \n %s", read);
	return (0);
}
