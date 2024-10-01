/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:33:30 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:30 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *chain, const char *subchain, size_t len)
{
	size_t	place;

	if (*subchain == '\0')
		return ((char *)chain);
	place = ft_strlen((char *)subchain);
	while (*chain != '\0' && len-- >= place)
	{
		if (*chain == *subchain && ft_memcmp(chain, subchain, place) == 0)
			return ((char *)chain);
		chain++;
	}
	return (NULL);
}
