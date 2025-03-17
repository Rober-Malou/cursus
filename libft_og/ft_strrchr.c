/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/17 14:33:37 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:37 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It looks for the last occurrence of the character c in s and returns a
// pointer to the occurrence

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *) &s[len]);
		len--;
	}
	return (NULL);
}
