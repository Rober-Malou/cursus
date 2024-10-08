/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:04:25 by robenite          #+#    #+#             */
/*   Updated: 2024/10/10 17:10:04 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	num = ft_calloc(ft_strlen(n) + 1, sizeof(char));
	i = ft_strlen(n);
	while (i >= 0)
	{
		num[i] = (n / 10);
		i--;
	}
	return (num);
}
