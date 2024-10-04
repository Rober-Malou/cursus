/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 04:57:52 by robenite          #+#    #+#             */
/*   Updated: 2024/10/04 14:24:34 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s3_len;
	char	s3;
	int		*s1_len;

	s3_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)ft_calloc(s3_len, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	ft_strlcpy(s3, s1);
	ft_strlcpy(s3[s1_len], s2);
	return (s3);
}
