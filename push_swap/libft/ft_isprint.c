/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:31:25 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:31:25 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checks if the int is part of the part of the ASCII table that is printable

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
