/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:30:02 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/24 20:24:24 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	first_and_last_row(char *str)
{
	while (*str)
	{
		if (*str != '1' && *str != '-')
			ft_exit("Error: Open border");
		str++;
	}
}

void	col_border(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = t_map.cols - 1;
	while (s[i] == '-' && s[i] != '\0')
		i++;
	while (s[j] == '-' && j >= 0)
		j--;
	if (s[i] != '1' || s[j] != '1')
	{
		printf("%d %d\n", i, j);
		ft_exit("Error: Open border");
	}
}

void	check_invalid_characters2(int i, int j)
{
	if (t_map.matrix[i][j] != 'N' && t_map.matrix[i][j] != 'S' &&
		t_map.matrix[i][j] != 'W' && t_map.matrix[i][j] != 'E' &&
		t_map.matrix[i][j] != '0' && t_map.matrix[i][j] != '1' &&
		t_map.matrix[i][j] != '-')
	{
		ft_exit("Error: Invalid symbol in map!");
	}
	if (t_map.matrix[i][j] == 'N' || t_map.matrix[i][j] == 'S' ||
		t_map.matrix[i][j] == 'W' || t_map.matrix[i][j] == 'E')
	{
		set_player_pos(j, i);
		set_player_dir_plane(t_map.matrix);
	}
}
