#include "../include/dyplom.h"

static void ft_norm(t_dyplom *dyplom)
{
	int			i;
	int			j;
	long double	k;

	i = 0;
	while (i < dyplom->k_rez)
	{
		j = 0;
		k = dyplom->rez[i]->u[0];
		while (j < dyplom->rez[i]->len)
		{
			
			dyplom->rez[i]->u[j] = dyplom->rez[i]->u[j] / k * 100;
			j++;
		}
		i++;
	}
}

void		check_appr(t_dyplom *dyplom)
{
	int	i;
	int	j;

	i = 0;
	while (i < dyplom->k_rez)
	{
		j = 0;
		while (j < dyplom->rez[i]->len)
		{
			dyplom->rez[i]->u[j] = exp( (-1) *
			powl( (dyplom->rez[i]->t[j] / dyplom->rez[i]->appr->tay), dyplom->rez[i]->appr->beta) );
			j++;
		}	
		i++;
	}
	ft_norm(dyplom);
}

void		create_appr(t_dyplom *dyplom)
{
	int		i;
	char	*file_name;
	FILE	*fd;

	printf("create approximate file\n");
	file_name = ft_strjoin(dyplom->sp, "appr.txt");
	fd = fopen(file_name, "a+");
	if (fd < 0)
		error(4);
	fclose(fd);
	fd = fopen(file_name, "w");
	i = 0;
	while (i < dyplom->k_rez)
	{
			fprintf(fd, "%d\t%Lf\t%Lf\t%Lf\t%Lf\t%Lf\r\n",
			dyplom->rez[i]->T, dyplom->rez[i]->appr->A, dyplom->rez[i]->appr->B,
			dyplom->rez[i]->appr->tay, dyplom->rez[i]->appr->beta,
			dyplom->rez[i]->appr->sum);
		i++;
	}
	if (fclose(fd) < 0)
		error(5);
}
