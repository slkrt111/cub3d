/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:10:09 by bhamani           #+#    #+#             */
/*   Updated: 2025/08/12 10:10:09 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_elements(t_data *data, char *line)
{
	char	*trimmed;
	int		result;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (FALSE);
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		result = parse_texture(data, trimmed, 'N');
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		result = parse_texture(data, trimmed, 'S');
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		result = parse_texture(data, trimmed, 'W');
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		result = parse_texture(data, trimmed, 'E');
	else if (ft_strncmp(trimmed, "F ", 2) == 0)
		result = parse_color(&data->floor_color, trimmed);
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
		result = parse_color(&data->ceiling_color, trimmed);
	else
	{
		free(trimmed);
		return (FALSE);
	}
	return (result);
}

static int	handle_map_line(t_data *data, char *line, int *map_ended)
{
	if (is_empty_line(line))
	{
		*map_ended = TRUE;
		return (TRUE);
	}
	if (*map_ended)
		return (print_error("Invalid map: content after empty line"), FALSE);
	if (!parse_map(data, line))
		return (FALSE);
	return (TRUE);
}

static int	handle_element_line(t_data *data, char *line)
{
	int	i;
	int	is_empty;

	i = 0;
	is_empty = 1;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n' && line[i] != '\r')
			is_empty = 0;
		i++;
	}
	if (!is_empty && !parse_elements(data, line))
		return (FALSE);
	return (TRUE);
}

static int	parse_lines(t_data *data)
{
	char	*line;
	int		map_started;
	int		map_ended;

	map_started = FALSE;
	map_ended = FALSE;
	line = get_next_line(data->fd);
	while (line)
	{
		if (!map_started && is_map_line(line))
		{
			if (!all_elements_parsed(data))
				return (free(line), get_next_line(-1), FALSE);
			map_started = TRUE;
		}
		if ((map_started && !handle_map_line(data, line, &map_ended))
			|| (!map_started && !handle_element_line(data, line)))
			return (free(line), FALSE);
		free(line);
		line = get_next_line(data->fd);
	}
	return (TRUE);
}

int	parse_file(t_data *data, char *filename)
{
	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		return (print_error("Cannot open file"), FALSE);
	if (!parse_lines(data))
		return (close(data->fd), FALSE);
	close(data->fd);
	return (TRUE);
}
