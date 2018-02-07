#include "../include/dyplom.h"

static void		print_mass(t_rez *rez, FILE* fd, int status, int mult)
{
	int			i;
	int			j;
	int			k;
	long double sum;

	k = 100;
	i = 0;
	while (i < rez->len)
	{
		j = 0;
		sum = 0;
		while (j < k && status == 1)
		{
			sum += rez->u[i + j];
			j++;
		}
		sum /= k;
		if (status == 1)
		{
			if (mult == 1)
				fprintf(fd, "%3.0Lf", sum * rez->len);
			else
				fprintf(fd, "%3.0Lf", sum);
		}
		else
		{
			if (mult == 1)
				fprintf(fd, "%3.0Lf", rez->u[i] * rez->len);
			else
				fprintf(fd, "%3.0Lf", rez->u[i]);
		}
		if (i != rez->len - k)
			fprintf(fd, " ");
		i += k;
	}
}

void			create_fdf(t_dyplom *dyplom, char *name, int status, int mult)
{
	int	i;
	FILE	*fd;

	printf("create fdf: %s\n", ft_strjoin(dyplom->sp, name));
	fd = fopen(ft_strjoin(dyplom->sp, name), "a+");
	if (fd < 0)
		error(4);
	fclose(fd);
	fd = fopen(ft_strjoin(dyplom->sp, name), "w");
	i = dyplom->k_rez - 1;
	while (i >= 0)
	{
		print_mass(dyplom->rez[i], fd, status, mult);
		if (i != 0)
			fprintf(fd, "\n");
		i--;
	}
	if (fclose(fd) < 0)
		error(5);
}
