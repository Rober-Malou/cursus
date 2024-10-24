/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:41:32 by robenite          #+#    #+#             */
/*   Updated: 2024/10/24 23:07:54 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	s1_len = ft_strlen((char *) s1);
	while (ft_strchr(set, s1[s1_len]) && s1_len != 0)
		s1_len--;
	return (ft_substr((char *) s1, 0, s1_len + 1));
}
