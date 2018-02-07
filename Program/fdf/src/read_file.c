/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:52:30 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 16:14:19 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		set_color(double z, char *str)
{
	int color;

	if (ft_atoi_base(str, 16) != 0)
		color = ft_atoi_base(str, 16);
	else if (z < 0)
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x32A862;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20 && z < 50)
		color = 0xFAECBE;
	else if (z >= 50 && z < 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xF8F8FF;
	else
		color = 0;
	return (color);
}

static char		*ft_getcolor(char *str)
{
	while (str[0] != 'x' && str[0] != '\0')
		str++;
	str++;
	if (str)
		return (str);
	else
		return (NULL);
}

static int		ft_points(char *line, int y, t_point ***points_line)
{
	char	**points_str;
	t_point	*buf_point;
	int		i;

	points_str = ft_strsplit(line, ' ');
	i = 0;
	while (points_str[i] != 0)
		i++;
	if (!((*points_line) = (t_point**)malloc(sizeof(t_point) * i)))
		error(2);
	i = 0;
	while (points_str[i] != 0)
	{
		buf_point = (t_point*)malloc(sizeof(t_point));
		buf_point->x = i;
		buf_point->y = y;
		buf_point->z = ft_atoi_base(points_str[i], 10);
		buf_point->color = set_color(buf_point->z,
			ft_getcolor(points_str[i]));
		(*points_line)[i] = buf_point;
		i++;
	}
	return (i);
}

void			read_file(t_fdf *fdf, int fd)
{
	int		y;
	char	*line;
	t_lines	*line_map;
	t_point	**points_line;

	y = 0;
	fdf->map->len = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		check_symbol(line);
		if (!(line_map = (t_lines*)malloc(sizeof(t_lines))))
			error(2);
		line_map->len = ft_points(line, y, &points_line);
		line_map->points = points_line;
		fdf->map->lines[y] = line_map;
		y++;
	}
	fdf->map->len = y;
	if (fdf->map->len == 0 || fdf->map->lines[0]->len == 0)
		error(1);
}
