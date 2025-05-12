/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malou <malou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:42:53 by robenite          #+#    #+#             */
/*   Updated: 2025/05/09 17:55:52 by malou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_ps_node
{
	int				*nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct ps_list	*target_node;
	struct ps_list	*previus;
	struct ps_list	*next;
}	t_ps_node;
#endif