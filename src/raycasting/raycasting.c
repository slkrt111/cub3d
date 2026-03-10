/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:50:57 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:50:57 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray_params(t_data *data, double angle, double *dx, double *dy)
{
	*dx = cos(angle);
	*dy = sin(angle);
}

void	set_step_x_and_side_dist(t_data *data, t_step_vars *v,
		int *map_x)
{
	if (v->dx < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (data->player.x - *map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (*map_x + 1.0 - data->player.x) * v->delta_dist_x;
	}
}

void	set_step_y_and_side_dist(t_data *data,
		t_step_vars *v, int *map_y)
{
	if (v->dy < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (data->player.y - *map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (*map_y + 1.0 - data->player.y) * v->delta_dist_y;
	}
}

void	calculate_step_and_side_dist(t_data *data, t_ray *ray,
	int *map_x, int *map_y)
{
	t_step_vars	v;

	init_ray_params(data, ray->angle, &v.dx, &v.dy);
	v.delta_dist_x = fabs(1 / v.dx);
	v.delta_dist_y = fabs(1 / v.dy);
	*map_x = (int)data->player.x;
	*map_y = (int)data->player.y;
	set_step_x_and_side_dist(data, &v, map_x);
	set_step_y_and_side_dist(data, &v, map_y);
}

void	set_step_x(t_data *data, t_dda_vars *v, int map_x)
{
	if (v->dx < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (data->player.x - map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (map_x + 1.0 - data->player.x) * v->delta_dist_x;
	}
}
