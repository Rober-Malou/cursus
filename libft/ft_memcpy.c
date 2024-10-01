/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:32:25 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:25 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (dest == src || !n)
		return (dest);
	while (count < n)
	{
		*((char *)dest + count) = *((char *)src + count);
		count++;
	}
	return (dest);
}
