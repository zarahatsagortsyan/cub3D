/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:28:44 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:32:03 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_clear(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			my_mlx_pixel_put(&t_map.data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	ft_free(void)
{
	free_matrix(t_map.matrix);
	free(g_game.mlx);
	free(g_game.mlx_win);
	free(t_map.data.path);
	free(t_map.data.img);
	free(t_map.data.addr);
	free(t_map.no.path);
	free(t_map.no.img);
	free(t_map.no.addr);
	free(t_map.so.path);
	free(t_map.so.img);
	free(t_map.so.addr);
	free(t_map.we.path);
	free(t_map.we.img);
	free(t_map.we.addr);
	free(t_map.ea.path);
	free(t_map.ea.img);
	free(t_map.ea.addr);
}

int	start(void)
{
	read_keys();
	ft_clear();
	ft_raycasting();
	mlx_put_image_to_window(g_game.mlx, g_game.mlx_win, t_map.data.img, 0, 0);
	mlx_do_sync(g_game.mlx);
	return (0);
}
