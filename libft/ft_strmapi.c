/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:07:31 by robenite          #+#    #+#             */
/*   Updated: 2024/10/10 17:10:09 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				stop;
	char			*str;

	i = 0;
	stop = ft_strlen(s);
	str = ft_calloc(stop + 1, sizeof(char));
	while (i <= stop)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
