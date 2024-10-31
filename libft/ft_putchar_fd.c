/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:24:06 by robenite          #+#    #+#             */
/*   Updated: 2024/10/31 01:00:58 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It writes a character in the file descriptor of your choosing

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
