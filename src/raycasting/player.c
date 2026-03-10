/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:50:48 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:50:48 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalize_angle(double angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	rotate_player(t_data *data, double rotation)
{
	data->player.angle = normalize_angle(data->player.angle + rotation);
	data->player.dx = cos(data->player.angle);
	data->player.dy = sin(data->player.angle);
}

static int	check_collision(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= data->map.width
		|| map_y < 0 || map_y >= data->map.height)
		return (1);
	if (data->map.grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	move_forward_backward(t_data *data, int direction)
{
	double	new_x;
	double	new_y;
	double	move_x;
	double	move_y;

	move_x = data->player.dx * 0.005 * direction;
	move_y = data->player.dy * 0.005 * direction;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	if (!check_collision(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!check_collision(data, data->player.x, new_y))
		data->player.y = new_y;
}

void	move_left_right(t_data *data, int direction)
{
	double	new_x;
	double	new_y;
	double	move_x;
	double	move_y;

	move_x = -data->player.dy * 0.005 * direction;
	move_y = data->player.dx * 0.005 * direction;
	new_x = data->player.x + move_x;
	new_y = data->player.y + move_y;
	if (!check_collision(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!check_collision(data, data->player.x, new_y))
		data->player.y = new_y;
}
