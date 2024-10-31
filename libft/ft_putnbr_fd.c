/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:19:16 by robenite          #+#    #+#             */
/*   Updated: 2024/10/31 01:05:05 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It converts an int into a char so it can be written in the file descriptor
// of your choosing

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
