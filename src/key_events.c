/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:13:20 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:13:30 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_exit(char *str)
{
	if (str == NULL)
		exit(0);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

int	ft_mlx_pressed(int keycode)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		t_map.keys.w = 1;
	else if (keycode == 1)
		t_map.keys.s = 1;
	else if (keycode == 0)
		t_map.keys.a = 1;
	else if (keycode == 2)
		t_map.keys.d = 1;
	else if (keycode == 123)
		t_map.keys.left = 1;
	else if (keycode == 124)
		t_map.keys.right = 1;
	return (0);
}

int	ft_mlx_released(int keycode)
{
	if (keycode == 13)
		t_map.keys.w = 0;
	else if (keycode == 1)
		t_map.keys.s = 0;
	else if (keycode == 0)
		t_map.keys.a = 0;
	else if (keycode == 2)
		t_map.keys.d = 0;
	else if (keycode == 123)
		t_map.keys.left = 0;
	else if (keycode == 124)
		t_map.keys.right = 0;
	return (0);
}
