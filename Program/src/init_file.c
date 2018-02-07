#include "../include/dyplom.h"

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

t_rez			*init_rez(char *file)
{
	t_rez	*rez;
	int		n;

	n = ft_lines(file);
	if (!(rez = (t_rez*)malloc(sizeof(t_rez))) ||
		!(rez->appr = (t_appr*)malloc(sizeof(t_appr))) ||
		!(rez->t = (long double*)malloc(sizeof(long double) * n)) ||
		!(rez->u = (long double*)malloc(sizeof(long double) * n)) ||
		!(rez->len = (int)malloc(sizeof(int))))
		error(2);
	rez->len = n;
	return (rez);
}

t_dyplom		*init_dyplom(int argc)
{
	t_dyplom *dyplom;

	if (argc == 1)
		error(0);
	if (!(dyplom = (t_dyplom*)malloc(sizeof(t_dyplom))) ||
		!(dyplom->rez = (t_rez**)malloc(sizeof(t_rez) * (argc - 1))))
		error(2);
	dyplom->k_rez = argc - 1;
	return (dyplom);
}
