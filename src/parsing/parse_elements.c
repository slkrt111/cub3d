/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:09:34 by bhamani           #+#    #+#             */
/*   Updated: 2025/08/12 09:09:34 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*extract_path(char *line)
{
	int		i;
	int		start;
	int		end;
	char	*path;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	start = i;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
		i++;
	end = i;
	if (start == end)
		return (NULL);
	path = malloc(sizeof(char) * (end - start + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (start < end)
		path[i++] = line[start++];
	path[i] = '\0';
	return (path);
}

static int	set_texture(char **texture, char *path, char *err)
{
	if (*texture)
	{
		print_error(err);
		get_next_line(-1);
		free(path);
		return (FALSE);
	}
	*texture = path;
	return (TRUE);
}

int	parse_texture(t_data *data, char *line, char dir)
{
	char	*path;

	path = extract_path(line);
	if (!path)
		return (print_error("Invalid texture path"), FALSE);
	if (dir == 'N' && !set_texture(&data->textures.north,
			path, "Duplicate NO texture element"))
		return (free(line), FALSE);
	if (dir == 'S' && !set_texture(&data->textures.south,
			path, "Duplicate SO texture element"))
		return (free(line), FALSE);
	if (dir == 'W' && !set_texture(&data->textures.west,
			path, "Duplicate WE texture element"))
		return (free(line), FALSE);
	if (dir == 'E' && !set_texture(&data->textures.east,
			path, "Duplicate EA texture element"))
		return (free(line), FALSE);
	return (free(line), TRUE);
}

static int	parse_rgb_values(char **rgb, t_color *color)
{
	int		i;
	int		value;
	char	*trimmed;

	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (FALSE);
	i = 0;
	while (i < 3)
	{
		trimmed = ft_strtrim(rgb[i], " \t\n\r");
		if (!trimmed)
			return (FALSE);
		value = ft_atoi(trimmed);
		free(trimmed);
		if (value < 0 || value > 255)
			return (FALSE);
		if (i == 0)
			color->r = value;
		else if (i == 1)
			color->g = value;
		else if (i == 2)
			color->b = value;
		i++;
	}
	return (TRUE);
}

int	parse_color(t_color *color, char *line)
{
	char	*color_str;
	char	**rgb;
	int		result;

	if (!check_duplicate_color(color, line))
		return (FALSE);
	color_str = extract_path(line);
	if (!color_str)
		return (print_error("Invalid color format"), FALSE);
	rgb = ft_split(color_str, ',');
	free(color_str);
	if (!rgb)
		return (print_error("Error parsing color values"), FALSE);
	result = parse_rgb_values(rgb, color);
	free_rgb(rgb);
	if (!result)
	{
		get_next_line(-1);
		print_error("Invalid RGB values (0-255)");
	}
	return (free(line), result);
}
