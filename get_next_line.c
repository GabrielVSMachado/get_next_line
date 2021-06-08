/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvitor-s <gvitor-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:52:22 by gvitor-s          #+#    #+#             */
/*   Updated: 2021/06/08 19:34:30 by gvitor-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		*buffer[1024];
	char			*tmp;
	int				i;
	ssize_t			from_read;

	if (buffer[fd])
		*line = ft_strjoin(*line, buffer[fd]);
	buffer[fd] = malloc(BUFFER_SIZE + 1);
	while (TRUE)
	{
		from_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (from_read == -1)
			return (free(buffer[fd]), (-1));
		else if (from_read == 0)
			return (0);
		buffer[fd][ft_strlen(buffer[fd])] = '\0';
		i = 0;
		while (buffer[fd][i] != '\n' && buffer[fd][i])
			i++;
		if (buffer[fd][i] == '\n' && i != 0)
		{
			tmp = ft_substr(buffer[fd], 0, i - 1);
			if (!tmp)
			{
				free(buffer[fd]);
				return (free(tmp), (-1));
			}
			*line = ft_strjoin(*line, tmp);
			return (free(tmp), 1);
		}
		else
			*line = ft_strjoin(*line, buffer[fd]);
		buffer[fd] += i + 1;
	}
}

