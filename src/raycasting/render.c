/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:51:09 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:51:09 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->data + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*src;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		src = img->data + (y * img->line_len + x * (img->bpp / 8));
		return (*(unsigned int *)src);
	}
	return (0);
}

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_to_int(data->floor_color);
	ceiling_color = rgb_to_int(data->ceiling_color);
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 1200)
		{
			if (y < 800 / 2)
				put_pixel(data->mlx.screen, x, y, ceiling_color);
			else
				put_pixel(data->mlx.screen, x, y, floor_color);
			x++;
		}
		y++;
	}
}

static int	get_wall_texture_index(t_ray *ray)
{
	if (ray->wall_side == 0)
	{
		if (cos(ray->angle) > 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (sin(ray->angle) > 0)
			return (1);
		else
			return (0);
	}
}

void	draw_textured_wall(t_data *data, int x, t_ray *ray)
{
	t_draw_vars	v;

	v.texture_index = get_wall_texture_index(ray);
	v.texture = data->mlx.textures[v.texture_index];
	v.tex_x = (int)(ray->wall_x * (double)v.texture->width);
	if ((ray->wall_side == 0 && cos(ray->angle) > 0)
		|| (ray->wall_side == 1 && sin(ray->angle) < 0))
		v.tex_x = v.texture->width - v.tex_x - 1;
	v.step = (double)v.texture->height / ray->line_height;
	v.tex_pos = (ray->draw_start - 800 / 2 + ray->line_height / 2)
		* v.step;
	v.y = ray->draw_start;
	while (v.y <= ray->draw_end)
	{
		v.tex_y = (int)v.tex_pos & (v.texture->height - 1);
		v.tex_pos += v.step;
		v.color = get_pixel(v.texture, v.tex_x, v.tex_y);
		put_pixel(data->mlx.screen, x, v.y, v.color);
		v.y++;
	}
}
