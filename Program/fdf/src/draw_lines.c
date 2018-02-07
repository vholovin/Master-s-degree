/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:48:03 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:50:24 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		point_out_window(t_point *point)
{
	if (!(point->x > W + 200 || point->x <= 0 ||
		point->y > H + 200 || point->y <= 0))
		return (1);
	else
		return (0);
}

static void		draw_vertical(t_fdf *fdf, t_draw_line line,
		t_point p1, t_point p0)
{
	int	x;
	int	y;
	int	i;

	draw_pixel(fdf, p0.x, p0.y, p0.color);
	x = p0.x;
	y = p0.y + line.sy;
	i = 1;
	while (i <= line.dy)
	{
		if (line.d > 0)
		{
			line.d += line.d2;
			x += line.sx;
		}
		else
			line.d += line.d1;
		draw_pixel(fdf, x, y, draw_color(p0.color, p1.color, line.dy, i));
		i++;
		y += line.sy;
	}
}

static void		draw_horizontal(t_fdf *fdf, t_draw_line line,
		t_point p1, t_point p0)
{
	int	x;
	int	y;
	int	i;

	draw_pixel(fdf, p0.x, p0.y, p0.color);
	x = p0.x + line.sx;
	y = p0.y;
	i = 1;
	while (i <= line.dx)
	{
		if (line.d > 0)
		{
			line.d += line.d2;
			y += line.sy;
		}
		else
			line.d += line.d1;
		draw_pixel(fdf, x, y, draw_color(p0.color, p1.color, line.dx, i));
		i++;
		x += line.sx;
	}
}

void			draw_lines(t_fdf *fdf, t_point point1, t_point point0)
{
	t_draw_line line;

	if (!point_out_window(&point0) && !point_out_window(&point1))
		return ;
	line.dx = fabs(point1.x - point0.x);
	line.dy = fabs(point1.y - point0.y);
	line.sx = point1.x >= point0.x ? 1 : -1;
	line.sy = point1.y >= point0.y ? 1 : -1;
	if (line.dy <= line.dx)
	{
		line.d = (line.dy << 1) - line.dx;
		line.d1 = line.dy << 1;
		line.d2 = (line.dy - line.dx) << 1;
		draw_horizontal(fdf, line, point1, point0);
	}
	else
	{
		line.d = (line.dx << 1) - line.dy;
		line.d1 = line.dx << 1;
		line.d2 = (line.dx - line.dy) << 1;
		draw_vertical(fdf, line, point1, point0);
	}
}
