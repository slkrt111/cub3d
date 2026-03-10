/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:51:16 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:51:16 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

static double	deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

static double	rad_to_deg(double radians)
{
	return (radians * 180.0 / PI);
}

void	draw_wall_slice(t_data *data, int x, t_ray *ray)
{
	draw_textured_wall(data, x, ray);
}

int	render_frame(t_data *data)
{
	draw_floor_ceiling(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.screen->img_ptr, 0, 0);
	return (0);
}
