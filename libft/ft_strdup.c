/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:21:48 by robenite          #+#    #+#             */
/*   Updated: 2024/10/06 22:48:04 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	n;

	c = ft_calloc(ft_strlen(s), sizeof(char));
	n = 0;
	if (!c)
		return (NULL);
	while (s[n])
	{
		c[n] = s[n];
		n++;
	}
	c[n] = 0;
	return (c);
}
