/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:32:20 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:20 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compares the two strings for n bites and returns -x if s2 is bigger +x if 
// s1 is bigger and 0 if they are equal
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*((unsigned char *)s1 + count) == *((unsigned char *)s2 + count))
			count++;
		else
			return ((*((unsigned char *)s1 + count))
				- *((unsigned char *)s2 + count));
	}
	return (0);
}
