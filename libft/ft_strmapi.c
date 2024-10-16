/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:31 by robenite          #+#    #+#             */
/*   Updated: 2024/10/14 19:26:43 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	stop;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	stop = ft_strlen(s);
	str = ft_calloc(stop + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < stop)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
