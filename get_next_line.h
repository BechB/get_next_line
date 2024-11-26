/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:54:04 by bbousaad          #+#    #+#             */
/*   Updated: 2023/01/15 13:04:41 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	ft_putnbr_fd(int n, int fd);
int		ft_strlen_n_o(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif