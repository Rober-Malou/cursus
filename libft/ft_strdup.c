/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:30:48 by robenite          #+#    #+#             */
/*   Updated: 2024/10/01 01:36:10 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	ptr = (const char )ft_calloc(1, n);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s, n);
	return (ptr);
}
