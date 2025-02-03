/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:31 by robenite          #+#    #+#             */
/*   Updated: 2024/10/31 02:16:33 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copies the string into a new one and in the new one applies the function of
// your choosing to the new one

#include "libft.h"

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
	return (str);
}
