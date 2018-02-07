/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:29:44 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:30:27 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			if (x != fdf->map->lines[y]->len - 1)
				draw_lines(fdf, *fdf->map->lines[y]->points[x + 1],
					*fdf->map->lines[y]->points[x]);
			if (y != fdf->map->len - 1)
				if (fdf->map->lines[y + 1]->points[x])
					draw_lines(fdf, *fdf->map->lines[y + 1]->points[x],
					*fdf->map->lines[y]->points[x]);
			x++;
		}
		y++;
	}
}

int		expose_hook(t_fdf *fdf)
{
	draw(fdf);
	return (0);
}
