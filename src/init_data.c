/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:07:18 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 12:07:18 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data_part1(t_data *data)
{
	data->textures.north = NULL;
	data->textures.south = NULL;
	data->textures.west = NULL;
	data->textures.east = NULL;
	data->floor_color.r = -1;
	data->floor_color.g = -1;
	data->floor_color.b = -1;
	data->floor_color.a = 255;
	data->ceiling_color.r = -1;
	data->ceiling_color.g = -1;
	data->ceiling_color.b = -1;
	data->ceiling_color.a = 255;
	data->map.grid = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.player_x = -1;
	data->map.player_y = -1;
	data->map.player_dir = '\0';
	data->player.x = 0;
	data->player.y = 0;
	data->player.angle = 0;
	data->player.dx = 0;
	data->player.dy = 0;
}

void	init_data_part2(t_data *data)
{
	data->mlx.mlx_ptr = NULL;
	data->mlx.win_ptr = NULL;
	data->mlx.screen = NULL;
	data->mlx.textures[0] = NULL;
	data->mlx.textures[1] = NULL;
	data->mlx.textures[2] = NULL;
	data->mlx.textures[3] = NULL;
	data->fd = -1;
	data->filename = NULL;
}
