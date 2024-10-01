/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:33:37 by robenite          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:37 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count != '\0'])
		count++;
	while (count != 0)
	{
		if (s[count] == c)
			return ((char *)s);
		count--;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
