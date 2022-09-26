/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:53:55 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/23 19:17:02 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*remove_empty_lines(int fd)
{
	int		res;
	char	*line;

	res = get_next_line(fd, &line);
	while (res > 0)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			res = get_next_line(fd, &line);
			continue ;
		}
		else
			break ;
	}
	return (line);
}

void	tmp_map(int fd)
{
	int		r;
	char	*result;
	char	*tmp;
	char	*line;
	char	*a;

	a = remove_empty_lines(fd);
	result = NULL;
	line = ft_strjoin(a, "\n");
	free(a);
	result = line;
	r = get_next_line(fd, &line);
	while (r > 0)
	{
		a = ft_strjoin(line, "\n");
		tmp = ft_strjoin(result, a);
		free(result);
		free(a);
		result = tmp;
		free(line);
		r = get_next_line(fd, &line);
	}
	t_map.tmp_map = ft_split(result, '\n');
	free(line);
	free(result);
}

void	r_and_c(void)
{
	int	i;

	i = 0;
	while (t_map.tmp_map[i] != 0)
		i++;
	t_map.rows = i;
}

void	parsing_map(int fd)
{
	tmp_map(fd);
	close(fd);
	r_and_c();
	matrix();
	check_borders();
}
