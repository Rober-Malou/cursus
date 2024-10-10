/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:13:21 by robenite          #+#    #+#             */
/*   Updated: 2024/10/10 18:17:07 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, '/n', 1);
}
