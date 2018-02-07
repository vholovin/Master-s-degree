/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:46:54 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:47:54 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			draw_pixel(t_fdf *fdf, double x, double y, int color)
{
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
}

static int		hex_c(int r, int g, int b)
{
	int	hex;

	hex = r * 256 * 256 + g * 256 + b;
	return (hex);
}

static int		rgb_c(int hex, int color)
{
	int r;
	int g;
	int b;

	if (color == 'r')
	{
		r = hex / (16 * 16 * 16 * 16);
		return (r);
	}
	if (color == 'g')
	{
		g = hex % (16 * 16 * 16 * 16) / (16 * 16);
		return (g);
	}
	if (color == 'b')
	{
		b = hex % (16 * 16);
		return (b);
	}
	return (0);
}

static int		delta_c(int c0, int c1, int d, int color)
{
	int dr;
	int dg;
	int db;

	if (color == 'r')
	{
		dr = abs((rgb_c(c0, 'r') - rgb_c(c1, 'r')) / d);
		return (dr);
	}
	if (color == 'g')
	{
		dg = abs((rgb_c(c0, 'g') - rgb_c(c1, 'g')) / d);
		return (dg);
	}
	if (color == 'b')
	{
		db = abs((rgb_c(c0, 'b') - rgb_c(c1, 'b')) / d);
		return (db);
	}
	return (0);
}

int				draw_color(int c0, int c1, int d, int k)
{
	int r;
	int g;
	int b;

	while (d > 50)
	{
		d /= 10;
		k /= 10;
	}
	if (rgb_c(c0, 'r') > rgb_c(c1, 'r'))
		r = rgb_c(c0, 'r') - delta_c(c0, c1, d, 'r') * k;
	else
		r = rgb_c(c0, 'r') + delta_c(c0, c1, d, 'r') * k;
	if (rgb_c(c0, 'g') > rgb_c(c1, 'g'))
		g = rgb_c(c0, 'g') - delta_c(c0, c1, d, 'g') * k;
	else
		g = rgb_c(c0, 'g') + delta_c(c0, c1, d, 'g') * k;
	if (rgb_c(c0, 'b') > rgb_c(c1, 'b'))
		b = rgb_c(c0, 'b') - delta_c(c0, c1, d, 'b') * k;
	else
		b = rgb_c(c0, 'b') + delta_c(c0, c1, d, 'b') * k;
	return (hex_c(r, g, b));
}
