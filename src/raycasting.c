/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:20:25 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/25 15:47:52 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_ray_dirs(void)
{
	if (g_game.ray_dir_x < 0)
	{
		g_game.step_x = -1;
		g_game.side_dist_x = (g_game.posx - g_game.mapx) * g_game.delta_dist_x;
	}
	else
	{
		g_game.step_x = 1;
		g_game.side_dist_x = (g_game.mapx - g_game.posx + 1.0)
			* g_game.delta_dist_x;
	}
	if (g_game.ray_dir_y < 0)
	{
		g_game.step_y = -1;
		g_game.side_dist_y = (g_game.posy - g_game.mapy) * g_game.delta_dist_y;
	}
	else
	{
		g_game.step_y = 1;
		g_game.side_dist_y = (g_game.mapy - g_game.posy + 1.0)
			* g_game.delta_dist_y;
	}
}

void	ft_wall_hit(void)
{
	while (vars.hit == 0)
	{
		if (g_game.side_dist_x < g_game.side_dist_y)
		{
			g_game.side_dist_x += g_game.delta_dist_x;
			g_game.mapx += g_game.step_x;
			vars.side = 0;
		}
		else
		{
			g_game.side_dist_y += g_game.delta_dist_y;
			g_game.mapy += g_game.step_y;
			vars.side = 1;
		}
		if (t_map.matrix[g_game.mapx][g_game.mapy] == '1')
			vars.hit = 1;
	}
	if (vars.side == 0)
		g_game.perp_wall_dist = (g_game.mapx - g_game.posx + (1 - g_game.step_x)
				/ 2) / g_game.ray_dir_x;
	else
		g_game.perp_wall_dist = (g_game.mapy - g_game.posy + (1 - g_game.step_y)
				/ 2) / g_game.ray_dir_y;
}

void	ft_init_vars(void)
{
	vars.line_height = (int)(WIN_HEIGHT / g_game.perp_wall_dist);
	vars.draw_start = -vars.line_height / 2 + WIN_HEIGHT / 2;
	vars.draw_end = vars.line_height / 2 + WIN_HEIGHT / 2;
	if (vars.draw_start < 0)
		vars.draw_start = 0;
	if (vars.draw_end >= WIN_HEIGHT)
		vars.draw_end = WIN_HEIGHT - 1;
	if (vars.side == 0)
		vars.wall_x = g_game.posy + g_game.perp_wall_dist * g_game.ray_dir_y;
	else
		vars.wall_x = g_game.posx + g_game.perp_wall_dist * g_game.ray_dir_x;
	vars.wall_x -= floor((vars.wall_x));
	vars.tex_x = (int)(vars.wall_x * (double)(TEXTURE_SIZE));
	if (vars.side == 0 && g_game.ray_dir_x > 0)
		vars.tex_x = TEXTURE_SIZE - vars.tex_x - 1;
	if (vars.side == 1 && g_game.ray_dir_y < 0)
		vars.tex_x = TEXTURE_SIZE - vars.tex_x - 1;
	vars.step = 1.0 * TEXTURE_SIZE / vars.line_height;
	vars.tex_pos = (vars.draw_start - WIN_HEIGHT / 2 + vars.line_height
			/ 2) * vars.step;
}

void	ft_draw(int *x)
{
	int	y;

	y = vars.draw_start;
	while (y < vars.draw_end)
	{
		vars.tex_y = (int)vars.tex_pos & (TEXTURE_SIZE - 1);
		vars.tex_pos += vars.step;
		if (vars.side == 0)
		{
			if (g_game.step_x > 0)
				vars.color = get_color(&t_map.so, vars.tex_x, vars.tex_y);
			else
				vars.color = get_color(&t_map.no, vars.tex_x, vars.tex_y);
		}
		else
		{
			if (g_game.step_y > 0)
				vars.color = get_color(&t_map.we, vars.tex_x, vars.tex_y);
			else
				vars.color = get_color(&t_map.ea, vars.tex_x, vars.tex_y);
		}
		my_mlx_pixel_put(&t_map.data, *x, y, vars.color);
		y++;
	}
}

void	ft_raycasting(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars.color = 0;
	while (x < WIN_WIDTH)
	{
		raycasting_vars(x);
		ft_ray_dirs();
		ft_wall_hit();
		ft_init_vars();
		y = 0;
		while (y++ < vars.draw_start)
			my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.c_color));
		ft_draw(&x);
		y = vars.draw_end;
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(&t_map.data, x, y, rgb(t_map.f_color));
			y++;
		}
		vars.buffer[x] = g_game.perp_wall_dist;
		x++;
	}
}
