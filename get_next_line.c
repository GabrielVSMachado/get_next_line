/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:52:22 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/06/14 14:32:19 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static int	check_newline(char **str);
static int	treat_readed_str(char **src, char **dst, int fd);
static int	treat_excess(char **src, char **dst, int fd);

int	get_next_line(int fd, char **line)
{
	static char	*buffer[1024];

	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, 1);
		return (treat_readed_str(&buffer[fd], line, fd));
	}
	else
		return (treat_excess(&buffer[fd], line, fd));
}

static int	check_newline(char **str)
{
	int	i;

	i = 0;
	while (*str[i] != '\n' && *str[i] != '\0')
		i++;
	return (i);
}

static int	treat_readed_str(char **src, char **dst, int fd)
{
	char	*tmp;
	char	*new_line;

	while (read(fd, *src, BUFFER_SIZE) > 0)
	{
		if (*src[check_newline(src)] == '\n')
			return (treat_excess(src, dst, fd));
		tmp = ft_strdup(*src);
		if (!tmp)
			return (free(tmp), gnl_ERROR);
		new_line = ft_strjoin(*dst, tmp);
		free(*dst);
		*dst = new_line;
	}
	return (free(tmp), gnl_READ);
}

static int	treat_excess(char **src, char **dst, int fd)
{
	int		where_n_line;
	char	*tmp;
	char	*new_line;

	where_n_line = check_newline(src);
	if (*src[where_n_line] == '\n')
	{
		tmp = ft_substr(*src, 0, where_n_line);
		if (!tmp)
			return (free(*src), gnl_ERROR);
		new_line = ft_strjoin(*dst, tmp);
		free(tmp);
		free(*dst);
		*dst = new_line;
		tmp = ft_substr(*src, where_n_line + 1, ft_strlen(*src) - where_n_line);
		free(*src);
		if (ft_strlen(tmp) == 0)
			*src = NULL;
		else
			*src = tmp;
		return (gnl_READ);
	}
	return (treat_readed_str(src, dst, fd));
}
