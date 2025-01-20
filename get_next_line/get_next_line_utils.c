/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:53:47 by robenite          #+#    #+#             */
/*   Updated: 2024/12/31 22:17:24 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		o;

	i = 0;
	o = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[o++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		s3[o++] = s2[i++];
	}
	s3[o] = '\0';
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count ++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	n;

	c = malloc(ft_strlen(s) + 1);
	n = 0;
	if (!c)
		return (NULL);
	while (s[n])
	{
		c[n] = s[n];
		n++;
	}
	c[n] = '\0';
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
