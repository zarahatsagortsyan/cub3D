/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:51:15 by zhatsago          #+#    #+#             */
/*   Updated: 2022/09/24 18:13:32 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*the_line(char *tmp)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = 0;
	while (tmp && tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = tmp[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*leftover(char *tmp)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp && tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	ptr = (char *)malloc(ft_gnl_strlen(tmp) - i + 1);
	if (!ptr)
		return (NULL);
	i++;
	while (tmp[i])
		ptr[j++] = tmp[i++];
	ptr[j] = '\0';
	free(tmp);
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	int			r;
	char		*buf;
	static char	*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		tmp = ft_gnl_strjoin(tmp, buf);
		if (ft_gnl_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	*line = the_line(tmp);
	tmp = leftover(tmp);
	if (r < 0)
		return (-1);
	if (r == 0 && !tmp)
		return (0);
	return (1);
}
