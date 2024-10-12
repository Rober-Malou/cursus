/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 04:57:52 by robenite          #+#    #+#             */
/*   Updated: 2024/10/12 04:54:13 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		o;

	i = 0;
	o = 0;
	s3 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
		s3[o++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[o++] = s2[i];
	s3[o] = 0;
	return (s3);
}
