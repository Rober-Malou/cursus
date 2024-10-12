/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:19:16 by robenite          #+#    #+#             */
/*   Updated: 2024/10/12 02:15:51 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	digit = n + 48;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 9)
	{
		write(fd, &digit, 1);
		n /= 10;
	}
}
