/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:04:25 by robenite          #+#    #+#             */
/*   Updated: 2024/10/31 00:22:52 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It converts a number(int) to the same number as a char

#include "libft.h"

// Checks how many positions an int have as in 10 or 100 etc

static size_t	ft_intlen(int nbr)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		count++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_intlen(nbr);
	if (nbr < 0)
		len++;
	num = (char *)ft_calloc(len + 1, sizeof(char));
	if (!num)
		return (NULL);
	if (nbr < 0)
	{
		num[0] = '-';
		nbr = -nbr;
	}
	while (len > 0 && nbr != 0)
	{
		num[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n == 0)
		num[0] = '0';
	return (num);
}
