/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/09/17 14:29:06 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:29:06 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Erases the n bite and everything afterwards of a string writing in
// it's place '\0'

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
