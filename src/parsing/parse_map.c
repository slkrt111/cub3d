/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:13:37 by bhamani           #+#    #+#             */
/*   Updated: 2025/08/12 10:13:37 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**realloc_map(char **old_map, int old_height, int new_height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (new_height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_height && old_map)
	{
		new_map[i] = old_map[i];
		i++;
	}
	while (i < new_height)
	{
		new_map[i] = NULL;
		i++;
	}
	new_map[i] = NULL;
	if (old_map)
		free(old_map);
	return (new_map);
}

static int	copy_and_check_char(t_data *data, char *map_line, char *line, int i)
{
	map_line[i] = line[i];
	if (!is_valid_char(line[i]))
	{
		print_error("Invalid character in map");
		return (FALSE);
	}
	if (!check_player_char(data, line[i], i, data->map.height))
		return (FALSE);
	return (TRUE);
}

static int	process_map_line(t_data *data, char *line)
{
	int		len;
	int		i;
	char	*map_line;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	map_line = malloc(sizeof(char) * (len + 1));
	if (!map_line)
		return (FALSE);
	i = 0;
	while (i < len)
	{
		if (!copy_and_check_char(data, map_line, line, i))
			return (free(map_line), FALSE);
		i++;
	}
	map_line[i] = '\0';
	data->map.grid[data->map.height] = map_line;
	if (len > data->map.width)
		data->map.width = len;
	return (TRUE);
}

int	pad_map_lines(t_data *data)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	while (i < data->map.height)
	{
		len = ft_strlen(data->map.grid[i]);
		if (len < data->map.width)
		{
			new_line = malloc(sizeof(char) * (data->map.width + 1));
			if (!new_line)
				return (FALSE);
			fill_line_padding(new_line, data->map.grid[i],
				len, data->map.width);
			free(data->map.grid[i]);
			data->map.grid[i] = new_line;
		}
		i++;
	}
	return (TRUE);
}

int	parse_map(t_data *data, char *line)
{
	char	**new_grid;

	new_grid = realloc_map(data->map.grid, data->map.height,
			data->map.height + 1);
	if (!new_grid)
	{
		print_error("Memory allocation failed");
		return (FALSE);
	}
	data->map.grid = new_grid;
	if (!process_map_line(data, line))
		return (FALSE);
	data->map.height++;
	return (TRUE);
}
