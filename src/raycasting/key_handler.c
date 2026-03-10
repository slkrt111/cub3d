/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:40:05 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 12:40:05 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_close(t_data *data)
{
	free_mlx_resources(data);
	free_data(data);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_close(data);
	if (keycode == 119 || keycode == 87)
		data->mlx.keys[keycode] = 1;
	if (keycode == 115 || keycode == 83)
		data->mlx.keys[keycode] = 1;
	if (keycode == 97 || keycode == 65)
		data->mlx.keys[keycode] = 1;
	if (keycode == 100 || keycode == 68)
		data->mlx.keys[keycode] = 1;
	if (keycode == 65361)
		data->mlx.keys[keycode] = 1;
	if (keycode == 65363)
		data->mlx.keys[keycode] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 87)
		data->mlx.keys[keycode] = 0;
	if (keycode == 115 || keycode == 83)
		data->mlx.keys[keycode] = 0;
	if (keycode == 97 || keycode == 65)
		data->mlx.keys[keycode] = 0;
	if (keycode == 100 || keycode == 68)
		data->mlx.keys[keycode] = 0;
	if (keycode == 65361)
		data->mlx.keys[keycode] = 0;
	if (keycode == 65363)
		data->mlx.keys[keycode] = 0;
	return (0);
}
