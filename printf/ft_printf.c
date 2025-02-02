/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:31:53 by robenite          #+#    #+#             */
/*   Updated: 2025/02/02 02:20:55 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_chek(char format, va_list args);
static int	pointer_f(unsigned long args, char *base);
static int	hexa_f(unsigned int args, char *base);
static int	ft_putnbr_ish_no_sign_fd(unsigned int args);

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
			return_counter += ft_putchar_ish_fd(text[control_counter], 1);
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
		r_counter = ft_putchar_ish_fd(va_arg(args, int), 1);
	else if (format == 's')
		r_counter = ft_putstr_ish_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		r_counter = pointer_f(va_arg(args, unsigned long),
				"0123456789abcdef");
	else if (format == 'd' || format == 'i')
		r_counter = ft_putnbr_ish_fd(va_arg(args, int), 1);
	else if (format == 'u')
		r_counter = ft_putnbr_ish_no_sign_fd(va_arg(args, unsigned int));
	else if (format == 'x')
		r_counter = hexa_f(va_arg(args, unsigned long),
				"0123456789abcdef");
	else if (format == 'X')
		r_counter = hexa_f(va_arg(args, unsigned long),
				"0123456789ABCDEF");
	else if (format == '%')
		r_counter = ft_putchar_ish_fd('%', 1);
	return (r_counter);
}

static int	pointer_f(unsigned long args, char *base)
{
	int	sum;

	sum = 0;
	if (!args)
	{
		sum = ft_putstr_ish_fd("(nil)", 1);
		return (sum);
	}
	sum += ft_putstr_ish_fd("0x", 1);
	sum += hexa_p(args, base);
	return (sum);
}

static int	hexa_f(unsigned int args, char *base)
{
	int	sum;

	sum = 0;
	if (args >= 16)
		sum += hexa_f(args / 16, base);
	sum += ft_putchar_ish_fd(base[args % 16], 1);
	return (sum);
}

static int	ft_putnbr_ish_no_sign_fd(unsigned int args)
{
	char	c;
	int		count;

	count = 0;
	if (args >= 10)
		count += ft_putnbr_ish_no_sign_fd(args / 10);
	c = (args % 10) + '0';
	count += ft_putchar_ish_fd(c, 1);
	return (count);
}
