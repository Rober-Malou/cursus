/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:30:34 by robenite          #+#    #+#             */
/*   Updated: 2025/02/16 03:32:31 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set(t_list *colum_a, int argc, char **argv)
{
	int	n;
	int	*num;

	n = 1;
	while (n < argc)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (NULL);
		*num = ft_atoi(argv[n]);
		if (!colum_a)
			colum_a = ft_lstnew(num);
		else
			ft_lstadd_back(&colum_a, ft_lstnew(num));
		n++;
	}
	return (colum_a);
}
