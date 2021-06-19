/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:38:18 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/06/19 12:46:46 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static int	treat_newline(char **src, char *p, char **line);
static int	treat_read_str(char **src, char **dst, int *from_read);
static int	check_error(int *fd, char **result, char **line);

int	get_next_line(int fd, char **line)
{
	char		*result;
	static char	*buffer;
	int			from_read;

	if (check_error(&fd, &result, line) == gnl_ERROR)
		return (gnl_ERROR);
	from_read = 1;
	while (from_read > 0)
	{
		from_read = read(fd, result, BUFFER_SIZE);
		if (buffer != NULL && ft_strchr(buffer, '\n') != NULL)
			return (treat_newline(&buffer, ft_strchr(buffer, '\n'), line));
		from_read = treat_read_str(&result, &buffer, &from_read);
	}
	if (from_read == -1)
	{
		free(result);
		free(buffer);
		return (gnl_ERROR);
	}
	treat_read_str(&buffer, line, &from_read);
	free(buffer);
	free(result);
	return (gnl_EOF);
}

static int	treat_read_str(char **src, char **dst, int *from_read)
{
	char	*tmp;

	if (!*dst)
	{
		*dst = ft_substr("", 0, 0);
		if (!*dst)
			return (gnl_ERROR);
	}
	if (*from_read >= 0)
	{
		tmp = ft_strjoin(*dst, *src);
		if (!tmp)
			return (gnl_ERROR);
		free(*dst);
		*dst = tmp;
		if (*from_read == 0)
			free(tmp);
	}
	return (*from_read);
}

static int	treat_newline(char **src, char *p, char **line)
{
	char	*tmp;
	int		len;
	char	*new_line;

	len = p - *src;
	tmp = ft_substr(*src, 0, len);
	if (!tmp)
		return (gnl_ERROR);
	if (*line)
		new_line = ft_strjoin("", tmp);
	else
	{
		new_line = ft_strjoin(*line, tmp);
		free(tmp);
	}
	if (!new_line)
		return (gnl_ERROR);
	*line = new_line;
	free(tmp);
	tmp = ft_substr(*src, len + 1, ft_strlen(*src));
	if (!tmp)
		return (gnl_ERROR);
	free(*src);
	*src = tmp;
	return (gnl_READ);
}

static int	check_error(int *fd, char **result, char **line)
{
	if (*fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (gnl_ERROR);
	*result = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!*result)
	{
		*result = NULL;
		return (gnl_ERROR);
	}
	return (0);
}
