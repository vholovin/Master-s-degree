/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:49:02 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 13:50:20 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		ft_lines(char *file)
{
	int		fd;
	int		n_lines;
	char	buf;

	fd = 0;
	n_lines = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		error(1);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			n_lines++;
	}
	close(fd);
	return (n_lines);
}

static t_loc	*init_move_size_rot(t_loc *loc)
{
	loc->x_move = 0;
	loc->y_move = 0;
	return (loc);
}

t_fdf			*init_fdf(char **argv)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))) ||
		!(fdf->map = (t_map*)malloc(sizeof(t_map))) ||
		!(fdf->map->lines = (t_lines**)malloc(sizeof(t_lines)
			* ft_lines(argv[1]))) ||
		!(fdf->center = (t_point*)malloc(sizeof(t_point))) ||
		!(fdf->loc = (t_loc*)malloc(sizeof(t_loc))))
		error(2);
	fdf->loc = init_move_size_rot(fdf->loc);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W, H, "42_fdf_project");
	return (fdf);
}
