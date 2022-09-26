/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:51:24 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:19:03 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init(int fd)
{
	t_map.keys.w = 0;
	t_map.keys.s = 0;
	t_map.keys.d = 0;
	t_map.keys.a = 0;
	g_game.dirx = 0;
	g_game.diry = 0;
	g_game.move_speed = 0.08;
	g_game.planex = 0;
	g_game.planey = 0;
	g_game.rot_speed = 0.04;
	g_game.posx = 0;
	g_game.posy = 0;
	get_cols(fd);
}
