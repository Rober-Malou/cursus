/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/17 14:33:21 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:21 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (0);
	count = 0;
	while ((s1[count] || s2[count]) && count < n)
	{
		if ((unsigned char)s1[count] != (unsigned char)s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return (0);
}
