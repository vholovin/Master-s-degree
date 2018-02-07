/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:51:04 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 15:33:36 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;

	fd = check_file(argc, argv);
	fdf = init_fdf(argv);
	read_file(fdf, fd);
	tutorial();
	adaptive_size(fdf);
	adaptive_rotate(fdf, 40, -35, 32);
	search_center(fdf);
	mlx_hook(fdf->win, 2, 5, key_hook, fdf);
	mlx_expose_hook(fdf->win, expose_hook, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
