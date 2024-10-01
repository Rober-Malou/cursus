/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:41:32 by robenite          #+#    #+#             */
/*   Updated: 2024/09/26 22:25:30 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>



char	*ft_strtrim(char const *s1, char const *set)
{
	char	trim;
	int		s1_len;
	int		count;
	int		count_2;
	int		count_3;

	count_3 = 0;
	count_2 = 0;
	count = 0;
	s1_len = ft_strlen(s1);
	trim = (char *)malloc(s1_len);
	if (trim == NULL)
		return (NULL);
	while (s1[count] != "/0")
	{
		while (s1[count] != set[count_2] && set[count_2] != "/0")
		{
			trim[count_3] = s1[count];
			count_2++;
			count_3++;
		}
		if (s1[count] == set[count_2])
			count_2++;
		count++;
	}
	trim[count_3 +1] = '/0';
	return (trim);
}
