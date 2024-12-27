/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:13:20 by robenite          #+#    #+#             */
/*   Updated: 2024/10/24 23:08:53 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
