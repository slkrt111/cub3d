/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:49:31 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:49:31 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*create_image(t_data *data, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(data->mlx.mlx_ptr, width, height);
	if (!img->img_ptr)
	{
		free(img);
		return (NULL);
	}
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	img->width = width;
	img->height = height;
	return (img);
}

static t_img	*load_texture(t_data *data, char *path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!texture)
		return (NULL);
	texture->img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			path, &texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		free(texture);
		return (NULL);
	}
	texture->data = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_len, &texture->endian);
	return (texture);
}

int	load_textures(t_data *data)
{
	data->mlx.textures[0] = load_texture(data, data->textures.north);
	data->mlx.textures[1] = load_texture(data, data->textures.south);
	data->mlx.textures[2] = load_texture(data, data->textures.west);
	data->mlx.textures[3] = load_texture(data, data->textures.east);
	if (!data->mlx.textures[0] || !data->mlx.textures[1]
		|| !data->mlx.textures[2] || !data->mlx.textures[3])
	{
		print_error("Failed to load textures");
		return (FALSE);
	}
	return (TRUE);
}

void	init_player(t_data *data)
{
	data->player.x = (double)data->map.player_x + 0.5;
	data->player.y = (double)data->map.player_y + 0.5;
	if (data->map.player_dir == 'N')
		data->player.angle = 3 * PI / 2;
	else if (data->map.player_dir == 'S')
		data->player.angle = PI / 2;
	else if (data->map.player_dir == 'E')
		data->player.angle = 0;
	else if (data->map.player_dir == 'W')
		data->player.angle = PI;
	data->player.dx = cos(data->player.angle);
	data->player.dy = sin(data->player.angle);
}

int	init_mlx(t_data *data)
{
	int	i;

	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		return (FALSE);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			1200, 800, "Cub3D");
	if (!data->mlx.win_ptr)
		return (FALSE);
	data->mlx.screen = create_image(data, 1200, 800);
	if (!data->mlx.screen)
		return (FALSE);
	if (!load_textures(data))
	{
		free_mlx_resources(data);
		free_data(data);
		exit(FALSE);
	}
	init_player(data);
	i = -1;
	while (++i < 70000)
		data->mlx.keys[i] = 0;
	return (TRUE);
}
