/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:29:54 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:29:54 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Checkes if the int is a number in the ASCII table

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
