/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:32:31 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:31 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies n bites from a string to another. Careful, the memory may overlap
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (dest == src || !n)
		return (dest);
	if (dest < src)
	{
		while (count < n)
		{
			*((char *)dest + count) = *((char *)src + count);
			count++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((char *)dest + n -1) = *((char *)src + n -1);
			n--;
		}
	}
	return (dest);
}
