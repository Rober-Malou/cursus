/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malou <malou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:53:52 by robenite          #+#    #+#             */
/*   Updated: 2024/12/11 19:28:17 by malou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_h
# define get_next_line_h

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*looking(int fd);
char	*found(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
// int		main(int argc, char *argv[]);

#endif