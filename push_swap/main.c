/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:33:23 by robenite          #+#    #+#             */
/*   Updated: 2025/02/16 22:56:40 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*colum_a;
//	t_list	*colum_b;
	int		cheker;

	cheker = cheks(*argv);
	if (cheker != 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	colum_a = NULL;
	colum_a = set(colum_a, argc, argv);
//	colum_b = NULL;
	t_list *current = colum_a;
	while (current)
	{
		ft_printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
