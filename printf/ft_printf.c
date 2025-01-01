/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 21:31:53 by robenite          #+#    #+#             */
/*   Updated: 2025/01/01 05:31:03 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_chek(char format, va_list args);
static int	hexa_f(unsigned long long args, char *base, int c);
static int	float_f(float args);
static int	ft_putnbr_ish_no_sign_fd(int args);

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
		r_counter = hexa_f(va_arg(args, unsigned long long), "0123456789abcdef",
				1);
	else if (format == 'd')
		r_counter = float_f(va_arg(args, double));
	else if (format == 'i')
		r_counter = ft_putnbr_ish_fd(va_arg(args, int), 1);
	else if (format == 'u')
		r_counter = ft_putnbr_ish_no_sign_fd(va_arg(args, int));
	else if (format == 'x')
		r_counter = hexa_f(va_arg(args, unsigned long long), "0123456789abcdef",
				1);
	else if (format == 'X')
		r_counter = hexa_f(va_arg(args, unsigned long long), "0123456789ABCDEF",
				1);
	else if (format == '%')
		r_counter = ft_putchar_ish_fd(va_arg(args, int), 1);
	return (r_counter);
}

static int	hexa_f(unsigned long long args, char *base, int c)
{
	int	sum;

	sum = 0;
	if (!args)
	{
		sum = ft_putstr_ish_fd("NULL", 1);
		return (sum);
	}
	if (c == 1)
	{
		sum += ft_putstr_ish_fd("0x", 1);
		c = 0;
	}
	while (args >= 16)
		sum += hexa_f(args / 16, base, c);
	sum += ft_putstr_ish_fd(&base[args % 16], 1);
	return (sum);
}

static int	float_f(float args)
{
	int		sum;
	int		control;
	float	left_over;

	sum = 0;
	control = (int)args;
	left_over = args;
	sum += ft_putnbr_ish_fd(args, 1);
	sum += ft_putchar_ish_fd('.', 1);
	left_over = left_over - control;
	while (left_over > 0)
	{
		left_over = left_over * 10;
		sum += ft_putnbr_ish_fd(left_over, 1);
		left_over = control;
		left_over = left_over - control;
	}
	return (sum);
}

static int	ft_putnbr_ish_no_sign_fd(int args)
{
	char	c;
	int		count;

	count = 0;
	if (args == -2147483648)
	{
		count += write(1, "2147483648", 10);
		return (count);
	}
	if (args < 0)
		args = -args;
	if (args >= 10)
	{
		ft_putnbr_ish_no_sign_fd(args / 10);
	}
	c = (args % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
