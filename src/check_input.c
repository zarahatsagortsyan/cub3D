/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:39:03 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/04 19:52:50 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}

int	check_map_name(char *string, char *ext)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(ext);
	while (string[i])
		i++;
	while (len--)
		i--;
	if (string[i] == '.')
		if (ft_strncmp((string + i - 1), ext, ft_strlen(ext)))
			return (1);
	return (0);
}

int	check_colors(void)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (t_map.f_color[i] < 0 || t_map.f_color[i] > 255)
			return (0);
		if (t_map.c_color[i] < 0 || t_map.c_color[i] > 255)
			return (0);
		if (t_map.c_color[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char *str)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}

char	**free_matrix(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	return (NULL);
}
