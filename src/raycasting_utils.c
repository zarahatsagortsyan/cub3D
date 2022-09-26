/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:27:10 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:27:54 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	raycasting_vars(int x)
{
	vars.hit = 0;
	g_game.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	g_game.ray_dir_x = g_game.dirx + g_game.planex * g_game.camera_x;
	g_game.ray_dir_y = g_game.diry + g_game.planey * g_game.camera_x;
	g_game.mapx = (int)g_game.posx;
	g_game.mapy = (int)g_game.posy;
	g_game.delta_dist_x = fabs(1 / g_game.ray_dir_x);
	g_game.delta_dist_y = fabs(1 / g_game.ray_dir_y);
}
