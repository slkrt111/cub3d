/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:19:18 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 11:19:18 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_players(t_data *data)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.grid[i] && data->map.grid[i][j])
		{
			if (data->map.grid[i][j] == 'N' || data->map.grid[i][j] == 'S'
				|| data->map.grid[i][j] == 'E' || data->map.grid[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_invalid_border_char(int i, int j, t_data *data, char c)
{
	if ((i == 0 || i == data->map.height - 1
			|| j == 0 || j == data->map.width - 1)
		&& (c == '0' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W'))
		return (1);
	return (0);
}

int	check_borders(t_data *data)
{
	int		i;
	int		j;
	int		line_len;
	char	c;

	i = -1;
	while (++i < data->map.height)
	{
		line_len = ft_strlen(data->map.grid[i]);
		j = 0;
		while (j < line_len && j < data->map.width)
		{
			c = data->map.grid[i][j];
			if (is_invalid_border_char(i, j, data, c))
			{
				if (c == '0')
					print_error("Map not closed: open space at border");
				else
					print_error("Map not closed: player cannot be on border");
				return (FALSE);
			}
			j++;
		}
	}
	return (TRUE);
}

int	is_map_closed(t_data *data)
{
	if (!check_borders(data))
		return (FALSE);
	if (!check_spaces(data))
		return (FALSE);
	return (TRUE);
}

int	validate_map(t_data *data)
{
	if (data->map.height == 0)
	{
		print_error("No map found");
		return (FALSE);
	}
	if (count_players(data) != 1)
	{
		print_error("Map must have exactly one player");
		return (FALSE);
	}
	if (data->map.player_dir == '\0')
	{
		print_error("No player found");
		return (FALSE);
	}
	if (!is_map_closed(data))
		return (FALSE);
	return (TRUE);
}
