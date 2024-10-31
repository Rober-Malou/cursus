/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:43:59 by robenite          #+#    #+#             */
/*   Updated: 2024/10/30 23:31:23 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Reserves a number of bites of memory and inicialices to '\0' so you won't
// have rubbish data by accident

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*ptr;

	ptr = (int *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
