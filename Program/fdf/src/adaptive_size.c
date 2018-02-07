/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:23:11 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 15:33:24 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	adaptive_size(t_fdf *fdf)
{
	int	x;
	int	y;
	int	m_x;
	int	m_y;

	m_x = 10;
	m_y = 10;
	y = 0;
	while (y != fdf->map->len)
	{
		x = 0;
		while (x != fdf->map->lines[y]->len)
		{
			fdf->map->lines[y]->points[x]->x *= m_x;
			fdf->map->lines[y]->points[x]->y *= m_y;
			x++;
		}
		y++;
	}
}
