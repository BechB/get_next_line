/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:53:40 by bbousaad          #+#    #+#             */
/*   Updated: 2023/01/14 09:07:46 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*next_line(char *l)
{
	int		i;
	char	*str;

	if (l[ft_strlen_n_o(l)])
	{
		i = (ft_strlen_n_o(l)) + 1;
		str = NULL;
		str = ft_strjoin(str, &l[i], -1, 0);
		free (l);
		return (str);
	}
	free (l);
	return (NULL);
}

char	*write_line(char *l)
{
	int		i;
	char	*str;

	if (!l[0])
		return (NULL);
	str = (char *)malloc((ft_strlen_n_o(l) + 2) * sizeof(char));
	i = -1;
	while (l[++i] != '\n' && l[i])
		str[i] = l[i];
	if (l[i] == '\n')
	{
		str[i] = l[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_line_fd(int fd, char *l)
{
	char	*buf;
	int		buf_len;

	buf_len = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (ft_strchr(l, '\n') == NULL && buf_len != 0)
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len == -1)
		{
			free(buf);
			free(l);
			return (NULL);
		}
		buf[buf_len] = '\0';
		l = ft_strjoin(l, buf, -1, 0);
	}
	free (buf);
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*l = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	l = read_line_fd(fd, l);
	if (!l)
		return (NULL);
	line = write_line(l);
	l = next_line(l);
	return (line);
}
