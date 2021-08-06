/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeoffro <lgeoffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:33:42 by lgeoffro          #+#    #+#             */
/*   Updated: 2021/07/25 22:30:21 by lgeoffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if ((src == 0) || (dst == 0))
		return (0);
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	read_and_join(int fd, char **buf_of_read,
						char **buf_of_line, int *bytes)
{
	char	*temporary_of_read;

	while (*bytes && ft_strchr_GNL(*buf_of_read, '\n') == HAVNT_BRK_LINE)
	{
		*bytes = read(fd, *buf_of_line, BUFFER_SIZE);
		(*buf_of_line)[*bytes] = '\0';
		if (*bytes < 0 || *bytes > BUFFER_SIZE)
		{
			free(*buf_of_line);
			return (-1);
		}
		temporary_of_read = *buf_of_read;
		*buf_of_read = ft_strjoin(temporary_of_read, *buf_of_line);
		free(temporary_of_read);
	}
	free(*buf_of_line);
	return (READ_AND_JOINED_OR_EOF);
}

char	*make_line_and_buf_of_read(char **line, char *buf_of_read, int bytes)
{
	int		position_of_brkline;
	int		len_of_buf_of_read;
	char	*new_buf_of_read;

	position_of_brkline = 0;
	len_of_buf_of_read = 0;
	new_buf_of_read = NULL;
	while (buf_of_read[position_of_brkline] != '\n'
		&& buf_of_read[position_of_brkline] != '\0')
		position_of_brkline++;
	*line = ft_substr(buf_of_read, 0, position_of_brkline + 1);
	if (bytes)
	{
		if (buf_of_read[position_of_brkline] == '\n')
			position_of_brkline++;
		len_of_buf_of_read = ft_strlen(buf_of_read + position_of_brkline);
		new_buf_of_read = ft_substr(buf_of_read, position_of_brkline,
				len_of_buf_of_read);
		if (!new_buf_of_read)
			return (NULL);
	}
	free(buf_of_read);
	return (new_buf_of_read);
}

int	lastline(char **line, int bytes)
{
	if (!bytes && *line[0] == '\0')
	{
		free(*line);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*bor;
	char			*line;
	char			*bol;
	int				bytes;

	line = NULL;
	bytes = 1;
	bol = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD || read(fd, bol, 0) == -1)
		return (GNL_ERROR);
	if (!bor)
	{
		bor = (char *)ft_calloc(1, 1);
		if (!bor)
			return (GNL_ERROR);
	}
	bol = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!bol)
		return (GNL_ERROR);
	if (read_and_join(fd, &bor, &bol, &bytes) == -1)
		return (GNL_ERROR);
	bor = make_line_and_buf_of_read(&line, bor, bytes);
	if (lastline(&line, bytes))
		return (GNL_FOUND_EOF);
	return (line);
}
