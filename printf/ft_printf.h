/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robenite <robenite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 00:32:14 by robenite          #+#    #+#             */
/*   Updated: 2025/02/02 02:20:51 by robenite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *text, ...);
int		ft_putchar_ish_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putstr_ish_fd(char *s, int fd);
int		ft_putnbr_ish_fd(int n, int fd);
int		hexa_p(unsigned long args, char *base);

#endif