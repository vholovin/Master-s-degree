/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:16:55 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:17:57 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		adaptive_center(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			fdf->map->lines[y]->points[x]->x =
				fdf->map->lines[y]->points[x]->x + W / 2
					- fdf->center->x - fdf->loc->x_move;
			fdf->map->lines[y]->points[x]->y =
				fdf->map->lines[y]->points[x]->y + H / 2
					- fdf->center->y - fdf->loc->y_move;
			x++;
		}
		y++;
	}
}

void			search_center(t_fdf *fdf)
{
	int		yl;
	int		xl;

	yl = fdf->map->len;
	xl = fdf->map->lines[yl - 1]->len;
	fdf->center->x = (fdf->map->lines[yl - 1]->points[xl - 1]->x +
			fdf->map->lines[0]->points[0]->x) / 2;
	fdf->center->y = (fdf->map->lines[yl - 1]->points[xl - 1]->y +
			fdf->map->lines[0]->points[0]->y) / 2 - 60;
	adaptive_center(fdf);
}
