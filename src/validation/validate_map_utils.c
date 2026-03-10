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

int	is_adjacent_space(t_data *data, int i, int j)
{
	int	prev_len;
	int	next_len;

	if (i > 0)
		prev_len = ft_strlen(data->map.grid[i - 1]);
	else
		prev_len = 0;
	if (i < data->map.height - 1)
		next_len = ft_strlen(data->map.grid[i + 1]);
	else
		next_len = 0;
	if ((i > 0 && (j >= prev_len || data->map.grid[i - 1][j] == ' '))
		|| (i < data->map.height - 1 && (j >= next_len
		|| data->map.grid[i + 1][j] == ' '))
		|| (j > 0 && data->map.grid[i][j - 1] == ' ')
		|| data->map.grid[i][j + 1] == ' ')
		return (1);
	return (0);
}

int	check_spaces(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.grid[i] && data->map.grid[i][j])
		{
			c = data->map.grid[i][j];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (is_adjacent_space(data, i, j))
				{
					print_error("Map not closed: space adjacent \
						to walkable area");
					return (FALSE);
				}
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == '\t'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '\r' || c == '\n')
		return (TRUE);
	return (FALSE);
}
