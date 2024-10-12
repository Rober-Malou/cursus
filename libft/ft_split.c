/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:37:59 by robenite          #+#    #+#             */
/*   Updated: 2024/10/12 03:05:35 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_nsplit(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	*ft_wordlen(char const *str, char c, int p)
{
	int	*len;

	len = 0;
	while (str[p] != c)
		len++;
	return (len);
}

char	*ft_wordscopy(int start, int finish)
{
	char	*word;

	word = (char *)malloc(finish - start);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		words;
	int		finish;
	int		start;

	words = ft_nsplit(s, c);
	split = ft_calloc(words, sizeof(char));
	i = 0;
	start = 0;
	finish = *ft_wordlen(s, c, start);
	while (i <= words)
	{
		*split[i] = *ft_wordscopy(start, finish);
		while (split[start] <= split[finish])
		{
			*split[start] = s[start];
			start++;
		}
		i++;
	}
	return (split);
}
