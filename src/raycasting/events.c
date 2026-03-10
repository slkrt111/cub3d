/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:50:11 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:50:11 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_textures_adapt(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->mlx.textures[i])
		{
			if (data->mlx.textures[i]->img_ptr)
				mlx_destroy_image(data->mlx.mlx_ptr,
					data->mlx.textures[i]->img_ptr);
			free(data->mlx.textures[i]);
		}
	}
}

void	free_mlx_resources(t_data *data)
{
	if (data->mlx.screen)
	{
		if (data->mlx.screen->img_ptr)
			mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.screen->img_ptr);
		free(data->mlx.screen);
	}
	free_textures_adapt(data);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
	{
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
	}
}

int	game_loop(t_data *data)
{
	move_player(data);
	render_frame(data);
	return (0);
}
