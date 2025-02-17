/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:29:11 by robenite          #+#    #+#             */
/*   Updated: 2025/02/16 22:49:24 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheks(char *argv)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (argv)
		flag += ft_isdigit(argv[count++]);
	return (flag);
}
