/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:31:53 by robenite          #+#    #+#             */
/*   Updated: 2024/12/30 03:48:50 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *text, ...)
{
	va_list	args;
	int		return_counter;
	int		control_counter;

	va_start(args, text);
	return_counter = 0;
	control_counter = 0;
	while (text[control_counter])
	{
		if (text[control_counter] == '%')
		{
			control_counter++;
			return_counter += format_chek(text[control_counter], args);
		}
		else
		{
			ft_putchar_fd(text[control_counter], 1);
			return_counter++;
		}
		control_counter++;
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
	else if (format == 's')
		r_counter = formater_one(format, args);
	else if (format == 'p')
		r_counter = hexa_min(args, "0123456789abcdef", 1);
	else if (format == 'd')
		r_counter = formater_number(format, args)
	else if (format == 'i') 
		r_counter = 
	else if (format == 'u') 
		r_counter = 
	else if (format == 'x') 
		r_counter = 
	else if (format == 'X') 
		r_counter = 
	else if (format == '%')
		r_counter = write(1, '%', 1);
	return (r_counter);
}

static int	formater_one(char format, va_list args)
{
	int	sum;

	if (format == 's')
	{
		while (args)
		{
			sum = ft_strlen(args);
			ft_putstr_fd(args, 1);
		}
	}
	return (sum);
}

static int	hexa_min(unsigned long long args, char *base, int c)
{
	int	sum;

	sum = 0;
	if (!args)
	{
		sum += ft_print_str("(nil)");
		return (sum);
	}
	if (c == 1)
	{
		sum += write(1, "0x", 2);
		c = 0;
	}
	while (args >= 16)
		sum += hexa_min(args / 16, base, c);
	sum += write(1, &base[args % 16], 1);
	return (sum);
}

static int	formater_number(char format, va_list args)
{
	int	sum;

	if (format == "i")
	{
		ft_putnbr_fd(args, 1);
		while (args > 0)
		{
			args = (int) args / 10;
			sum ++;
		}
	}
	else if (format == "d")
	{

	}
}

static int format_loat(float args)
{
	int	control;
	float	left_over;

	control = (int)args;
	left_over = args;
	ft_putnbr_fd(args, 1);
	write(1, ".", 1);
	left_over - control;
	while (left_over > 0)
	{
		left_over * 10;
		ft_putnbr_fd(left_over, 1);
		left_over = control;
		left_over = left_over - control;
	}
}
