/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:34:56 by robenite          #+#    #+#             */
/*   Updated: 2025/01/20 21:22:22 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_ish_fd(char c, int fd)
{
	int	count;

	count = 0;
	count += write(fd, &c, 1);
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_putstr_ish_fd(char *s, int fd)
{
	int	len;

	if (!s)
		len += ft_putstr_ish_fd("NULL", 1);
	else
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}

int	ft_putnbr_ish_fd(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr_ish_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}
