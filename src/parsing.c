/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:01:09 by salaverd          #+#    #+#             */
/*   Updated: 2022/09/23 19:18:00 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	parse_color(char *line, char mode)
{
	int		i;
	int		len;
	char	**colors;

	i = 0;
	len = 0;
	while (*line == ' ')
		line++;
	colors = ft_split(line, ',');
	while (colors[i++])
		len++;
	if (len != 3)
		ft_exit("Error: wrong color numbers");
	i = 0;
	while (i < 3)
	{
		if (mode == 'F')
			t_map.f_color[i] = ft_atoi(colors[i]);
		else if (mode == 'C')
			t_map.c_color[i] = ft_atoi(colors[i]);
		i++;
	}
	if (!check_colors())
		ft_exit("Error: wrong color numbers");
	free_matrix(colors);
}

char	*parse_texture_path(char *line)
{
	char	*path;
	int		fd;

	while (*line == ' ')
		line++;
	path = ft_strdup(line);
	if (!(check_map_name(path, ".xpm")))
		ft_exit ("Error: File extension error");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit ("File doesn't exist");
	else
		close (fd);
	return (path);
}

void	parsing_texture(char *line)
{
	while (*line == ' ')
	{
		t_map.rows_tmp++;
		line++;
	}
	if (line[0] == 'N' && line[1] == 'O')
	{
		t_map.no.path = parse_texture_path(line + 2);
	}
	else if (line[0] == 'S' && line[1] == 'O')
		t_map.so.path = parse_texture_path(line + 2);
	else if (line[0] == 'W' && line[1] == 'E')
		t_map.we.path = parse_texture_path(line + 2);
	else if (line[0] == 'E' && line[1] == 'A')
		t_map.ea.path = parse_texture_path(line + 2);
	else if (line[0] == 'F')
		parse_color(line + 1, 'F');
	else if (line[0] == 'C')
		parse_color(line + 1, 'C');
}

void	parsing(int fd)
{
	int		i;
	char	*line;

	i = 0;
	t_map.rows_tmp = 0;
	while (i < 6 && get_next_line(fd, &line))
	{
		t_map.rows_tmp++;
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		else
			parsing_texture(line);
		free(line);
		i++;
	}
	if (t_map.ea.path == NULL || t_map.we.path == NULL
		|| t_map.no.path == NULL || t_map.so.path == NULL)
		ft_exit("Error: missing texture");
	parsing_map(fd);
}
