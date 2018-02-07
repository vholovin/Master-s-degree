/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 20:04:17 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 15:34:04 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibX/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define W 1800
# define H 900

typedef struct	s_loc
{
	int			x_move;
	int			y_move;
}				t_loc;

typedef	struct	s_draw_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			d;
	int			d1;
	int			d2;
}				t_draw_line;

typedef	struct	s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_point;

typedef struct	s_lines
{
	t_point		**points;
	int			len;
}				t_lines;

typedef struct	s_map
{
	t_lines		**lines;
	int			len;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		*map;
	t_point		*center;
	t_loc		*loc;
}				t_fdf;

t_fdf			*init_fdf(char **argv);
int				check_file(int argc, char **argv);
int				ft_atoi_base(const char *str, int str_base);
void			read_file(t_fdf *fdf, int fd);
void			check_symbol(char *line);
void			error(int status);
void			adaptive_size(t_fdf *fdf);
void			adaptive_rotate(t_fdf *fdf, int x, int y, int z);
void			search_center(t_fdf *fdf);
void			tutorial(void);
int				expose_hook(t_fdf *fdf);
void			draw(t_fdf *fdf);
void			draw_lines(t_fdf *fdf, t_point point1, t_point point0);
void			draw_pixel(t_fdf *fdf, double x, double y, int color);
int				draw_color(int c0, int c1, int p0, int k);
int				key_hook(int keycode, t_fdf *fdf);
void			size(t_fdf *fdf, double xyz);
void			move(t_fdf *fdf, int status, int move);
#endif
