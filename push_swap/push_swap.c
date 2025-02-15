/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:33:23 by robenite          #+#    #+#             */
/*   Updated: 2025/02/15 04:51:53 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		n;
	t_list	*head;

	n = 1;
	head = NULL;
	while (n < argc)
	{
		if (!head)
			head = ft_lstnew(argv[n]);
		else
			ft_lstadd_back(&head, ft_lstnew(argv[n]));
		n++;
	}
	t_list *current = head;
    while (current)
    {
        ft_printf("%s\n", (char *)current->content);
        current = current->next;
    }
	return (0);
}
