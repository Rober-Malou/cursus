/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:37:59 by robenite          #+#    #+#             */
/*   Updated: 2024/10/07 22:20:52 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_nsplit(char *str, char c)
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

char *ft_wordscopy()
{

}

char	**ft_split(char const *s, char c)
{
	char	*split;
	int	i;
	int	j;
	int	words;

	split = ft_calloc(ft_nsplit(s, c), sizeof(char));
	i = 0;
	j = 0;
	words = ft_nsplit;
	while (i <= words)
	{
		split[i] = ft_wordscopy();
	}
}
