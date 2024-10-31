/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:21:48 by robenite          #+#    #+#             */
/*   Updated: 2024/10/31 01:59:58 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a pointer to a new string that is a copy of s

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	n;

	c = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	n = 0;
	if (!c)
		return (NULL);
	while (s[n])
	{
		c[n] = s[n];
		n++;
	}
	return (c);
}
