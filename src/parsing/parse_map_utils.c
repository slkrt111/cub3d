/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamani <bhamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:21:31 by bhamani           #+#    #+#             */
/*   Updated: 2025/08/12 10:24:30 by bhamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_line_padding(char *new_line, char *old, int len, int width)
{
	int	j;

	j = 0;
	while (j < len)
	{
		new_line[j] = old[j];
		j++;
	}
	while (j < width)
		new_line[j++] = ' ';
	new_line[j] = '\0';
}

int	finalize_map(t_data *data)
{
	if (!pad_map_lines(data))
	{
		print_error("Failed to pad map lines");
		return (FALSE);
	}
	return (TRUE);
}

int	check_player_char(t_data *data, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->map.player_dir != '\0')
		{
			get_next_line(-1);
			print_error("Multiple players found");
			return (FALSE);
		}
		data->map.player_x = x;
		data->map.player_y = y;
		data->map.player_dir = c;
	}
	return (TRUE);
}
