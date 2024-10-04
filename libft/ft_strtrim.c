/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 05:41:32 by robenite          #+#    #+#             */
/*   Updated: 2024/10/03 15:58:45 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>



char	*ft_strtrim(char const *s1, char const *set)
{
	char	trim;
	int	i;
	int f;

	i = 0;
	f = (ft_strlen(s1) - 1);
	trim = (char *)ft_calloc(ft_strlen(s1), 1);
}
