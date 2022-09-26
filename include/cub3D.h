/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:49:19 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/24 20:45:32 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1
# define WIN_WIDTH 1300
# define WIN_HEIGHT 1000
# define TEXTURE_SIZE 64
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <math.h>
# include "mlx.h" 
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_img
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_keys
{
	int		w;
	int		s;
	int		d;
	int		a;
	int		left;
	int		right;
}				t_keys;

struct s_map
{
	t_img		data;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_keys		keys;
	int			f_color[3];
	int			c_color[3];
	int			rows_tmp;
	int			rows;
	int			cols;
	char		**tmp_map;
	char		**matrix;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			mapx;
	int			mapy;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		move_speed;
	double		rot_speed;
	int			step_x;
	int			step_y;
	int			s_count;
	char		player_view;
}				t_game;

struct	s_vars
{
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		color;
	double	buffer[WIN_WIDTH];
	double	wall_x;
	double	step;
	double	tex_pos;
}		vars;

t_game	g_game;

int			ft_check_extension(char *path, char *ext);
int			get_next_line(int fd, char **line);
int			ft_exit(char *str);
int			ft_mlx_pressed(int keycode);
int			ft_mlx_released(int keycode);
void		get_cols(int fd);
void		init(int fd);
void		allocate_matrix(int rows, int cols);
void		parsing(int fd);
void		parsing_map(int fd);
int			ft_isspace(char *str);
int			check_map_name(char *string, char *ext);
int			check_ext(char *path, char *ext);
int			check_colors(void);
void		r_and_c(void);
char		**free_matrix(char **map);
int			check_invalid_characters(void);
void		check_invalid_characters2(int i, int j);
void		set_player_pos(int x, int y);
void		set_player_dir_plane(char **map);
void		set_player_dir_plane2(char **map);
int			check_on_one_start_position(char symbol, int *is_there);
void		set_mlx_images(void);
void		set_mlx_addresses(void);
void		matrix(void);
void		first_and_last_row(char *s);
void		col_border(char *s);
void		check_borders(void);
void		minus_check(int i, int j);
int			start(void);
void		read_keys(void);
void		ft_raycasting(void);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			rgb(int *colors);
int			get_color(t_img *data, int x, int y);
void		raycasting_vars(int x);
void		ft_free(void);

#endif
