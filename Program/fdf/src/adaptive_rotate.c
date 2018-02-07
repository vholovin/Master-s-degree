/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:20:14 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:25:04 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		adaptive_rotate_x(t_fdf *fdf, int a)
{
	int		x;
	int		y;
	double	y_buf;
	double	z_buf;

	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			y_buf = fdf->map->lines[y]->points[x]->y;
			z_buf = fdf->map->lines[y]->points[x]->z;
			fdf->map->lines[y]->points[x]->y = y_buf * cos(a * 3.14 / 180)
				- z_buf * sin(a * 3.14 / 180);
			fdf->map->lines[y]->points[x]->z = y_buf * sin(a * 3.14 / 180)
				+ z_buf * cos(a * 3.14 / 180);
			x++;
		}
		y++;
	}
}

static void		adaptive_rotate_y(t_fdf *fdf, int a)
{
	int		x;
	int		y;
	double	x_buf;
	double	z_buf;

	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			x_buf = fdf->map->lines[y]->points[x]->x;
			z_buf = fdf->map->lines[y]->points[x]->z;
			fdf->map->lines[y]->points[x]->x = x_buf * cos(a * 3.14 / 180)
				+ z_buf * sin(a * 3.14 / 180);
			fdf->map->lines[y]->points[x]->z = x_buf * sin(a * 3.14 / 180)
				* (-1) + z_buf * cos(a * 3.14 / 180);
			x++;
		}
		y++;
	}
}

static void		adaptive_rotate_z(t_fdf *fdf, int a)
{
	int		x;
	int		y;
	double	x_buf;
	double	y_buf;

	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			x_buf = fdf->map->lines[y]->points[x]->x;
			y_buf = fdf->map->lines[y]->points[x]->y;
			fdf->map->lines[y]->points[x]->x = x_buf * cos(a * 3.14 / 180)
				- y_buf * sin(a * 3.14 / 180);
			fdf->map->lines[y]->points[x]->y = x_buf * sin(a * 3.14 / 180)
				+ y_buf * cos(a * 3.14 / 180);
			x++;
		}
		y++;
	}
}

void			adaptive_rotate(t_fdf *fdf, int x, int y, int z)
{
	adaptive_rotate_x(fdf, x);
	adaptive_rotate_y(fdf, y);
	adaptive_rotate_z(fdf, z);
}
