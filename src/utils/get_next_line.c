/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:32:02 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 11:32:02 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	copy_chars(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*newline_pos;
	char	*temp;
	int		line_len;

	if (!*buffer)
		return (NULL);
	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line_len = newline_pos - *buffer + 1;
		line = malloc(sizeof(char) * (line_len + 1));
		if (!line)
			return (NULL);
		copy_chars(line, *buffer, line_len);
		temp = ft_strdup(newline_pos + 1);
		free(*buffer);
		*buffer = temp;
		return (line);
	}
	line = ft_strdup(*buffer);
	free(*buffer);
	*buffer = NULL;
	return (line);
}

static char	*append_to_buffer(char *buffer, char *read_buffer)
{
	char	*temp;

	if (!buffer)
		return (ft_strdup(read_buffer));
	temp = ft_strjoin(buffer, read_buffer);
	free(buffer);
	return (temp);
}

static char	*read_into_buffer(int fd, char *buffer)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		read_buffer[bytes_read] = '\0';
		buffer = append_to_buffer(buffer, read_buffer);
		if (!buffer)
		{
			free(read_buffer);
			return (NULL);
		}
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_into_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	return (extract_line(&buffer));
}
