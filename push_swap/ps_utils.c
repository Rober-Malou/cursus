/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malou <malou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:23:54 by malou             #+#    #+#             */
/*   Updated: 2025/05/09 17:55:57 by malou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_splits(char **splits, int o)
{
	while (--o >= 0)
		free(splits[o]);
	free(splits);
}

static int	ft_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_counting(const char *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			num++;
		i++;
	}
	return (num);
}

char	**ft_split(const char *s, char c)
{
	int		n_words;
	char	**splits;
	int		i;
	int		o;
	int		word_len;

	n_words = ft_counting(s, c);
	splits = (char **)ft_calloc(n_words + 1, sizeof(char *));
	i = 0;
	o = 0;
	if (!splits)
		return (NULL);
	while (s[i] && o < n_words)
	{
		while (s[i] && s[i] == c)
			i++;
		word_len = ft_word_len(&s[i], c);
		splits[o] = ft_substr(s, i, word_len);
		if (!splits[o])
			return (ft_free_splits(splits, o), NULL);
		i += word_len;
		o++;
	}
	splits[o] = NULL;
	return (splits);
}
