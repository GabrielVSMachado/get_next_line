/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:52:22 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/06/10 22:36:43 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static int	get_line(char **buffer, int fd);
static int	check_newline(char **str);
static char	*treat_readed_str(char **src, char **dst);

int	get_next_line(int fd, char **line)
{
	static char	*buffer[1024];

	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, 1);
}

static int	get_line(char **buffer, int fd)
{
	ssize_t		from_read;

	from_read = read(fd, *buffer, BUFFER_SIZE);
	if (from_read == gnl_ERROR)
		return (gnl_ERROR);
	else if (from_read == gnl_EOF)
		return (gnl_EOF);
	else
		return (gnl_READ);
}

static int	check_newline(char **str)
{
	int	i;

	i = 0;
	while (*str[i] != '\n' && *str[i] != '\0')
		i++;
	return (i);
}

static char	*treat_readed_str(char **src, char **dst)
{
	char	*tmp;
	int		position_newline;

	position_newline = check_newline(src);
	if (position_newline > 0)
	{
		tmp = ft_substr(*src, 0, position_newline);
	}
}
