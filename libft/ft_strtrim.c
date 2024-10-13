/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:41:32 by robenite          #+#    #+#             */
/*   Updated: 2024/10/13 09:32:56 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	triming(const char *set, char s)
{
	int	i;

	i = 0;
	while (s == set[i])
	{
		return (1);
	}
	return (0);
}

static char	*end_product(const char *s1, size_t beguining, size_t end)
{
	char	*trim;
	size_t	i;

	if (end <= 0 || beguining >= ft_strlen(s1))
		return (ft_strdup(""));
	trim = ft_calloc(end + 1, sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (i <= end)
	{
		trim[i] = s1[beguining + i];
		i++;
	}
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	e;

	i = 0;
	e = (ft_strlen(s1) - 1);
	if (e <= 0)
		return (ft_strdup(""));
	while (i +1 != e)
	{
		triming(set, s1[i]);
		i++;
		triming(set, s1[e]);
		e--;
	}
	return (end_product(s1, i, e - (i - 1)));
}
