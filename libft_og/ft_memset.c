/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:32:37 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:32:37 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It fills the first n bites with c in the string s

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)s + count) = c;
		count++;
	}
	return (s);
}
