#include "../include/dyplom.h"

static void		print_double(t_rez *rez, FILE* fd)
{
	int	i;

	i = 0;
	while (i < rez->len)
	{
			fprintf(fd, "%3.12Lf\t%3.12Lf\r\n", rez->t[i], rez->u[i]);
		i++;
	}
}

void	create_file(t_dyplom *dyplom)
{
	int		i;
	char	*file_name;
	FILE	*fd;

	i = 0;
	while (i < dyplom->k_rez)
	{
		printf("create file T = %d K\n", dyplom->rez[i]->T);
		if (dyplom->rez[i]->T < 100)
		{
			file_name = ft_strjoin(dyplom->sp, "0");
			file_name = ft_strjoin(file_name, ft_itoa_base(dyplom->rez[i]->T, 10));
		}
		else
			file_name = ft_strjoin(dyplom->sp, ft_itoa_base(dyplom->rez[i]->T, 10));
		file_name = ft_strjoin(file_name, ".txt");
		fd = fopen(file_name, "a+");
		if (fd < 0)
			error(4);
		fclose(fd);
		fd = fopen(file_name, "w");
		print_double(dyplom->rez[i], fd);
		if (fclose(fd) < 0)
			error(5);
		i++;
	}
}
