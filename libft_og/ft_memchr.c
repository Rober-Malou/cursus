/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:32:12 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:12 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It finds c in the first n bites of s and returns a pointer to the place it
// found c

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*((unsigned char *)s + count) == (unsigned char)c)
			return ((void *)s + count);
		count ++;
	}
	return (NULL);
}
