/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:33:15 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:15 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Counts the length of a string

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count ++;
	return (count);
}
