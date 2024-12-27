/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:31:53 by robenite          #+#    #+#             */
/*   Updated: 2024/12/27 04:01:26 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int ft_printf(char const *text, ...)
{
	va_list args;
	va_start(args, text);
	int	return_counter;
	int	control_counter;

	return_counter = 0;
	control_counter = 0;

	while (text[control_counter])
		{
			if(text[control_counter] == '%')
				{
					control_counter ++;
					return_counter += format_chek(text[control_counter], args);
				}
			else;
				{
					ft_putchar_fd(text[control_counter], 1);
					return_counter ++;
				}
			control_counter ++;
		}
	va_end(args);
	return (return_counter);
}

static int	format_chek(char format, va_list args)
{
	int	r_counter;

	r_counter = 0;
	if (format == 'c')
		r_counter = write(1, args, 1);
	else if(format == 's')
		r_counter =
	else if(format == 'p')
		r_counter =
	else if(format == 'd')
		r_counter =
	else if(format == 'i')
		r_counter =
	else if(format == 'u')
		r_counter =
	else if(format == 'x')
		r_counter =
	else if(format == 'X')
		r_counter =
	else if(format == '%')
		r_counter = write(1, '%', 1);
	return (r_counter);
}

