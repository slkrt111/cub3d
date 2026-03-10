/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:36:31 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 12:36:31 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_step_y(t_data *data, t_dda_vars *v, int map_y)
{
	if (v->dy < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (data->player.y - map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (map_y + 1.0 - data->player.y) * v->delta_dist_y;
	}
}

void	exec_dda_loop(t_data *data, t_dda_vars *v, int *map_x, int *map_y)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			(*map_x) += v->step_x;
			v->side = 0;
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			(*map_y) += v->step_y;
			v->side = 1;
		}
		if (data->map.grid[*map_y][*map_x] == '1')
			hit = 1;
	}
}

void	perform_dda(t_data *data, t_ray *ray, int *map_x, int *map_y)
{
	t_dda_vars	v;

	init_ray_params(data, ray->angle, &v.dx, &v.dy);
	v.delta_dist_x = fabs(1 / v.dx);
	v.delta_dist_y = fabs(1 / v.dy);
	calculate_step_and_side_dist(data, ray, map_x, map_y);
	set_step_x(data, &v, *map_x);
	set_step_y(data, &v, *map_y);
	exec_dda_loop(data, &v, map_x, map_y);
	ray->wall_side = v.side;
	if (v.side == 0)
		ray->distance = (*map_x - data->player.x + (1 - v.step_x) / 2) / v.dx;
	else
		ray->distance = (*map_y - data->player.y + (1 - v.step_y) / 2) / v.dy;
}

t_ray	cast_ray(t_data *data, double angle)
{
	t_ray	ray;
	int		map_x;
	int		map_y;
	double	dx;
	double	dy;

	ray.angle = normalize_angle(angle);
	ray.hit_wall = 0;
	perform_dda(data, &ray, &map_x, &map_y);
	ray.hit_wall = 1;
	init_ray_params(data, ray.angle, &dx, &dy);
	if (ray.wall_side == 0)
		ray.wall_x = data->player.y + ray.distance * dy;
	else
		ray.wall_x = data->player.x + ray.distance * dx;
	ray.wall_x -= floor(ray.wall_x);
	ray.line_height = (int)(800 / ray.distance);
	ray.draw_start = -ray.line_height / 2 + 800 / 2;
	if (ray.draw_start < 0)
		ray.draw_start = 0;
	ray.draw_end = ray.line_height / 2 + 800 / 2;
	if (ray.draw_end >= 800)
		ray.draw_end = 800 - 1;
	return (ray);
}

void	cast_rays(t_data *data)
{
	int		x;
	double	camera_x;
	double	ray_angle;
	t_ray	ray;
	double	fov_rad;

	fov_rad = FOV * PI / 180;
	x = 0;
	while (x < 1200)
	{
		camera_x = 2 * x / (double)1200 - 1;
		ray_angle = data->player.angle + camera_x * fov_rad / 2;
		ray = cast_ray(data, ray_angle);
		draw_wall_slice(data, x, &ray);
		x++;
	}
}
