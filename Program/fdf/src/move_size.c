/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:51:53 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 13:52:20 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	size(t_fdf *fdf, double xyz)
{
	int x;
	int y;

	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			fdf->map->lines[y]->points[x]->x *= xyz;
			fdf->map->lines[y]->points[x]->y *= xyz;
			fdf->map->lines[y]->points[x]->z *= xyz;
			x++;
		}
		y++;
	}
}

void	move(t_fdf *fdf, int status, int move)
{
	if (status == 2)
	{
		fdf->loc->x_move = move;
		fdf->loc->y_move = move;
	}
	else if (status == 1)
		fdf->loc->x_move += move;
	else if (status == 0)
		fdf->loc->y_move += move;
}
