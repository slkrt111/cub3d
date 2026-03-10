/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:44:02 by slebik            #+#    #+#             */
/*   Updated: 2025/08/12 11:44:02 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "libft.h"
# include "../mlx_linux/mlx.h"

# define BUFFER_SIZE 1024
# define TRUE 1
# define FALSE 0

# define FOV 50
# define PI 3.14159265359

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_dda_vars
{
	double	dx;
	double	dy;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_dda_vars;

typedef struct s_step_vars
{
	double	dx;
	double	dy;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
}	t_step_vars;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_draw_vars
{
	int		texture_index;
	t_img	*texture;
	int		tex_x;
	int		tex_y;
	int		y;
	double	step;
	double	tex_pos;
	int		color;
}	t_draw_vars;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	double	dx;
	double	dy;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	distance;
	int		hit_wall;
	int		wall_side;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x_tex;

	double	dx;
	double	dy;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
}	t_ray;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*screen;
	t_img	*textures[4];
	int		keys[70000];
}	t_mlx;

typedef struct s_data
{
	t_texture	textures;
	t_color		floor_color;
	t_color		ceiling_color;
	t_map		map;
	t_player	player;
	t_mlx		mlx;
	int			fd;
	char		*filename;
}	t_data;

int			parse_file(t_data *data, char *filename);
void		fill_line_padding(char *new_line, char *old, int len, int width);
int			finalize_map(t_data *data);
int			check_duplicate_color(t_color *color, char *line);
void		free_rgb(char **rgb);
int			check_player_char(t_data *data, char c, int x, int y);
int			parse_line(t_data *data, char *line);
int			parse_texture(t_data *data, char *line, char direction);
int			parse_color(t_color *color, char *line);
int			pad_map_lines(t_data *data);
int			parse_map(t_data *data, char *line);
int			is_map_line(char *line);
int			is_empty_line(char *line);
int			finalize_map(t_data *data);
int			all_elements_parsed(t_data *data);
char		*get_next_line(int fd);

int			validate_map(t_data *data);
int			is_map_closed(t_data *data);
int			count_players(t_data *data);
int			is_valid_char(char c);
int			is_adjacent_space(t_data *data, int i, int j);
int			is_invalid_border_char(int i, int j, t_data *data, char c);
int			check_borders(t_data *data);
int			is_adjacent_space(t_data *data, int i, int j);
int			check_spaces(t_data *data);

void		free_data(t_data *data);
void		free_map(t_map *map);
void		free_textures(t_texture *textures);
void		free_mlx_resources(t_data *data);

void		error_exit(char *message);
void		print_error(char *message);

int			init_mlx(t_data *data);
int			load_textures(t_data *data);
void		init_player(t_data *data);
t_img		*create_image(t_data *data, int width, int height);

int			render_frame(t_data *data);
void		draw_floor_ceiling(t_data *data);
void		draw_textured_wall(t_data *data, int x, t_ray *ray);
void		cast_rays(t_data *data);
void		draw_wall_slice(t_data *data, int x, t_ray *ray);

t_ray		cast_ray(t_data *data, double angle);
double		get_wall_distance(t_data *data, double angle,
				int *wall_side, double *wall_x);
void		perform_dda(t_data *data, t_ray *ray, int *map_x, int *map_y);
void		exec_dda_loop(t_data *data, t_dda_vars *v, int *map_x, int *map_y);
void		set_step_y(t_data *data, t_dda_vars *v, int map_y);
void		set_step_x(t_data *data, t_dda_vars *v, int map_x);
void		calculate_step_and_side_dist(t_data *data, t_ray *ray,
				int *map_x, int *map_y);
void		set_step_y_and_side_dist(t_data *data,
				t_step_vars *v, int *map_y);
void		set_step_x_and_side_dist(t_data *data, t_step_vars *v,
				int *map_x);
void		init_ray_params(t_data *data, double angle, double *dx, double *dy);

int			handle_keypress(int keycode, t_data *data);
int			handle_keyrelease(int keycode, t_data *data);
int			handle_close(t_data *data);
int			game_loop(t_data *data);

void		put_pixel(t_img *img, int x, int y, int color);
int			get_pixel(t_img *img, int x, int y);
int			rgb_to_int(t_color color);
double		normalize_angle(double angle);

void		move_player(t_data *data);
void		move_forward_backward(t_data *data, int direction);
void		move_left_right(t_data *data, int direction);
void		rotate_player(t_data *data, double rotation);

void		init_data_part1(t_data *data);
void		init_data_part2(t_data *data);

#endif 