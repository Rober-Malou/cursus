/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:32:14 by robenite          #+#    #+#             */
/*   Updated: 2025/02/05 18:07:05 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(char const *text, ...);
int	ft_putchar_ish_fd(char c, int fd);
int	ft_putstr_ish_fd(char *s, int fd);
int	ft_putnbr_ish_fd(int n, int fd);
int	hexa_f(unsigned int args, char *base);
#endif