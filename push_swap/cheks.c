/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:29:11 by robenite          #+#    #+#             */
/*   Updated: 2025/02/16 03:28:03 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lst_isdigit(t_list *lst);

int	cheks(t_list *lst)
{
	int	flag;

	flag = 0;
	flag += lst_isdigit(lst);
	return (flag);
}

static int	lst_isdigit(t_list *lst)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	while (lst)
	{
		c += ft_isdigit(*(int *)lst->content);
		r++;
		lst = lst->next;
	}
	ft_printf("%i\n%i\n", c, r);
	if (c == r)
		return (0);
	return (1);
}
