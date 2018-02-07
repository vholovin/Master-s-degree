/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:50:36 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 13:50:54 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		key_hook_size(int keycode, t_fdf *fdf)
{
	if (keycode == 24)
		size(fdf, 1.01);
	else if (keycode == 27)
		size(fdf, 0.99);
	else if (keycode == 30)
		size(fdf, 2);
	else if (keycode == 33)
		size(fdf, 0.5);
}

static void		key_hook_move(int keycode, t_fdf *fdf)
{
	if (keycode == 126)
		move(fdf, 0, 10);
	else if (keycode == 125)
		move(fdf, 0, -10);
	else if (keycode == 123)
		move(fdf, 1, 10);
	else if (keycode == 124)
		move(fdf, 1, -10);
	else if (keycode == 50)
		move(fdf, 2, 0);
}

static void		key_hook_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == 14)
		adaptive_rotate(fdf, 0, 0, 1);
	else if (keycode == 13)
		adaptive_rotate(fdf, 1, 0, 0);
	else if (keycode == 12)
		adaptive_rotate(fdf, 0, 0, -1);
	else if (keycode == 2)
		adaptive_rotate(fdf, 0, 1, 0);
	else if (keycode == 1)
		adaptive_rotate(fdf, -1, 0, 0);
	else if (keycode == 0)
		adaptive_rotate(fdf, 0, -1, 0);
}

int				key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	key_hook_move(keycode, fdf);
	key_hook_rotate(keycode, fdf);
	key_hook_size(keycode, fdf);
	search_center(fdf);
	draw(fdf);
	return (0);
}
