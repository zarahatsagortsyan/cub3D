/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:16:23 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/24 18:19:24 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	minus_check(int i, int j)
{
	if (i > 0 && t_map.matrix[i - 1][j] != '1' &&
		t_map.matrix[i - 1][j] != '-')
		ft_exit("Map error1");
	if (i < t_map.rows - 1 && t_map.matrix[i + 1][j] != '1' &&
		t_map.matrix[i + 1][j] != '-')
		ft_exit("Map error2");
	if (j > 0 && t_map.matrix[i][j - 1] != '1' &&
		t_map.matrix[i][j - 1] != '-')
		ft_exit("Map error3");
	if (j < t_map.cols - 1 && t_map.matrix[i][j + 1] != '1' &&
		t_map.matrix[i][j + 1] != '-')
		ft_exit("Map error4");
}
