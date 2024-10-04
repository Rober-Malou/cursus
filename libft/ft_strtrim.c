/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:41:32 by robenite          #+#    #+#             */
/*   Updated: 2024/10/04 15:54:55 by robenite         ###   ########.fr       */
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
		i++;
	}
	return (0);
}

static char	*end_product(const char *s1, size_t beguining, size_t end)
{
	char	*trim;
	size_t	i;

	if (end <= 0 || beguining >= ft_strlen(s1))
		return (ft_strdup(""));
	trim = (char *)ft_calloc(end + 1, sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < end)
	{
		trim[i] = s1[beguining + i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	e;

	i = 0;
	e = (ft_strlen(s1) - 1);
	if (ft_strlen(s1) == 0)
		return ((ft_strdup("")) while (triming(set, s1[i])) i++);
	while (triming(set, s1[e]))
		e--;
}
