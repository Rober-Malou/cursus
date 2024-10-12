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

#include "libft.h"

char	*ft_strnstr(const char *chain, const char *subchain, size_t len)
{
	size_t	i;
	size_t	o;

	if (subchain[0] == 0)
		return ((char *)chain);
	while (chain[i] && i < len)
	{
		while (chain[i + o] == subchain[o] && chain[i + o] && i + o < len)
		{
			o++;
			if (subchain[o] == 0)
				return ((char *)chain + i);
		}
		i++;
		o = 0;
	}
	return (0);
}
