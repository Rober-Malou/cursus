/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/17 14:33:09 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:09 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies src in dst, garanties the null terminator and returns the length of
// src

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}
