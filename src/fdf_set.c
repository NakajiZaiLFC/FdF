/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:00:17 by snakajim          #+#    #+#             */
/*   Updated: 2025/01/03 18:18:54 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	_get_color(char *str)
{
	char	*color_str;
	int		color;

	color = 0xFFFFFF;
	color_str = ft_strchr(str, ',');
	if (color_str)
	{
		color_str++;
		if (color_str[0] == '0' && (color_str[1] == 'x' || color_str[1] == 'X'))
			color = ft_atoi_base(color_str + 2, 16);
	}
	return (color);
}

static void	_set_point_values(t_point *point, char *str, int x, int y)
{
	point->x = x;
	point->y = y;
	point->z = ft_atoi(str);
	if (point->z > 1000000)
		point->z = 1000000;
	point->color = _get_color(str);
}

static bool	_process_line(char *line, t_map *map, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	if (!split)
		return (false);
	x = 0;
	while (split[x] && x < map->width)
	{
		_set_point_values(&map->points[y][x], split[x], x, y);
		x++;
	}
	free_split(split);
	return (true);
}

static bool	_read_and_set_points(int fd, t_map *map)
{
	char	*line;
	int		y;

	y = 0;
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (false);
		if (!_process_line(line, map, y))
		{
			free(line);
			return (false);
		}
		free(line);
		y++;
	}
	return (true);
}

bool	set_points_info(char *file_name, t_map *map)
{
	int		fd;
	bool	result;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	result = _read_and_set_points(fd, map);
	close(fd);
	return (result);
}
