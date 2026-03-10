/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphics2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:51:25 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 10:51:25 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_data *data)
{
	if (data->mlx.keys[119] || data->mlx.keys[87])
		move_forward_backward(data, 1);
	if (data->mlx.keys[115] || data->mlx.keys[83])
		move_forward_backward(data, -1);
	if (data->mlx.keys[97] || data->mlx.keys[65])
		move_left_right(data, -1);
	if (data->mlx.keys[100] || data->mlx.keys[68])
		move_left_right(data, 1);
	if (data->mlx.keys[65361])
		rotate_player(data, -0.01);
	if (data->mlx.keys[65363])
		rotate_player(data, 0.01);
}
