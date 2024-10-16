/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:51:26 by robenite          #+#    #+#             */
/*   Updated: 2024/10/16 16:05:47 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*previus_link;
	t_list	*next_link;

	while (lst->next != del)
		previus_link = lst->next;
	if (lst->next == del)
		next_link = lst->next;
	previus_link->next = next_link;
	free (del);
}