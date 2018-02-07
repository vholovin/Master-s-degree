#include "../include/dyplom.h"
/*
static t_rez	*set_min(t_rez *rez)
{
	int			i;
	long double min;

	i = 0;
	min = rez->u[i];
	while (i < rez->len)
	{
		if (min > rez->u[i])
			min = rez->u[i];
		i++;
	}
	i = 0;
	while (i < rez->len)
	{
		rez->u[i] += fabsl(min);
		i++;
	}
	return (rez);
}
*/
static int		search_i_max(t_rez *rez)
{
	int			i;
	int			i_max;
	long double	max;
	long double midl;

	i = 0;
	i_max = 0;
	max = rez->u[i];
	midl = (rez->u[i] + rez->u[i + 1] + rez->u[i + 2]) / 3;
	while (i < (rez->len / 2 + 1000))
	{
		if (max < rez->u[i])
		{
			if (midl > ((rez->u[i] + rez->u[i + 1] + rez->u[i + 2]) / 3))
			{	
				max = rez->u[i];
				i_max = i;
			}
			midl = (rez->u[i] + rez->u[i + 1] + rez->u[i + 2]) / 3;
		}
		i++;
	}
	return (i_max);
}

static t_rez	*set_rear(t_rez *rez)
{
	int			i;
	int			i_min;
	long double	min;

	i = rez->len - 1;
	i_min = rez->len;
	min = rez->u[i];
	while (i > (rez->len * 3 / 4))
	{
		if (min > rez->u[i])
		{
			min = rez->u[i];
			i_min = i;
		}
		i--;
	}
	rez->len = i_min;
	return (rez);
}

static t_rez    *set_front(t_rez *rez, int i_max)
{
	int			i;

	i = 0;
	while ((i_max + i) < rez->len)
	{
		rez->u[i] = rez->u[i_max + i];
		i++;
	}
	rez->len = i + 1;
	return (rez);
}

void			set_data(t_dyplom *dyplom)
{
	int i;
	int	*i_max;
	int i_start;
	int	i_finish;

	i_max = (int*)malloc(sizeof(int) * dyplom->k_rez);
	i = 0;
	i_finish = dyplom->rez[i]->len;
	while (i < dyplom->k_rez)
	{
		printf("set data in T = %d K\n", dyplom->rez[i]->T);
//		dyplom->rez[i] = set_min(dyplom->rez[i]);
		i_max[i] = search_i_max(dyplom->rez[i]);
		dyplom->rez[i] = set_rear(dyplom->rez[i]);
		if (i_finish > dyplom->rez[i]->len)
			i_finish = dyplom->rez[i]->len;
		i++;
	}
	i = 0;
	i_start = i_max[i];
	while (i < dyplom->k_rez)
	{
		if (i_start < i_max[i])
			i_start = i_max[i];
		dyplom->rez[i]->len = i_finish;
		i++;
	}
	i = 0;
	while (i < dyplom->k_rez)
	{
		dyplom->rez[i] = set_front(dyplom->rez[i], i_start);	
		i++;
	}
	free(i_max);
}
