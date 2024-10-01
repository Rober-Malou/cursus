/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:33:01 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:01 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;	
	size_t	src_count;
	size_t	value;

	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dest))
		value = ft_strlen(src) + size;
	else
		value = ft_strlen(src) + ft_strlen(dest);
	count = 0;
	while (dest[count] != '\0')
		count++;
	while (src[src_count] != '\0' && count + 1 < size)
	{
		dest[count] = src[src_count];
		src_count++;
		count++;
	}
	dest[count] = '\0';
	return (value);
}
