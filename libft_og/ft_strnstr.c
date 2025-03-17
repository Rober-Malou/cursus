/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/17 14:33:30 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:30 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It checks if a small string is inside of a big one in the given length and
// returns a pointer where the coincidence starts

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + o] == little[o] && big[i + o] && i + o < len)
		{
			o++;
			if (little[o] == 0)
				return ((char *)big + i);
		}
		i++;
		o = 0;
	}
	return (0);
}
