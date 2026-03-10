/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:28:58 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 11:28:58 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	init_data_part1(data);
	init_data_part2(data);
}

static int	check_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (FALSE);
	if (ft_strncmp(&filename[len - 4], ".cub", 4) != 0)
		return (FALSE);
	return (TRUE);
}

static int	handle_errors(int condition, t_data *data, char *msg)
{
	if (!condition)
	{
		if (msg)
			ft_putendl_fd(msg, 2);
		free_data(data);
		return (0);
	}
	return (1);
}

static void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, handle_keyrelease, data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17, handle_close, data);
	mlx_loop_hook(data->mlx.mlx_ptr, game_loop, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <map.cub>", 2);
		return (1);
	}
	if (!check_file_extension(argv[1]))
	{
		ft_putendl_fd("Error: File must have .cub extension", 2);
		return (1);
	}
	init_data(&data);
	data.filename = argv[1];
	if (!handle_errors(parse_file(&data, argv[1]), &data, NULL))
		return (1);
	if (!handle_errors(finalize_map(&data), &data, NULL))
		return (1);
	if (!handle_errors(validate_map(&data), &data, NULL))
		return (1);
	if (!handle_errors(init_mlx(&data), &data, "Failed to initialize graphics"))
		return (1);
	set_hooks(&data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
