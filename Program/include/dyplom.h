#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_appr
{
	long double	A;
	long double d_A;
	long double	B;
	long double d_B;
	long double	tay;
	long double d_tay;
	long double beta;
	long double d_beta;
	long double	sum;
}				t_appr;

typedef struct	s_rez
{
	int			T;
	long double	*t;
	long double	*u;
	int			len;
	t_appr		*appr;
}				t_rez;

typedef struct	s_dyplom
{
	t_rez		**rez;
	int			k_rez;
	char		*sp;
}				t_dyplom;

t_dyplom	*init_dyplom(int argc);
t_rez		*init_rez(char *file);
void		read_file(t_dyplom *dyplom, char **argv);
void		check_symbol(char *line);
void		error(int status);
void        set_data(t_dyplom *dyplom);
void		appr_data(t_dyplom *dyplom, int mezha);
void		create_folder(t_dyplom *dyplom);
void		create_file(t_dyplom *dyplom);
void		create_appr(t_dyplom *dyplom);
void        check_appr(t_dyplom *dyplom);
void		create_fdf(t_dyplom *dyplom, char *name, int status, int mult);
long double	ft_atoid(char *str, char symb);
char		*ft_itoa_base(int value, int base);
#endif
