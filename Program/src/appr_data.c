#include "../include/dyplom.h"

static long double	search_sum(long double A, long double B, long double tay, long double beta, t_rez *rez)
{
	long double	sum;
	int			i;

	i = 0;
	sum = 0;
	while (i < rez->len)
	{
		sum += powl((rez->u[i] - A - B * exp ( (-1) * powl((rez->t[i])/tay, beta) ) ), 2);
		i++;
	}
	return (sum);
}

static long double   init_A(t_rez *rez, double mezha)
{
	long double	sum;
	long double	sum_p;
	long double	sum_n;

	while (mezha)
	{
		sum = search_sum(rez->appr->A, rez->appr->B, rez->appr->tay, rez->appr->beta, rez);
		sum_p = search_sum(rez->appr->A - rez->appr->d_A, rez->appr->B, rez->appr->tay, rez->appr->beta, rez);
		sum_n = search_sum(rez->appr->A + rez->appr->d_A, rez->appr->B, rez->appr->tay, rez->appr->beta, rez);
		if (sum > sum_n)
			rez->appr->A += rez->appr->d_A;
		else if (sum > sum_p)
			rez->appr->A -= rez->appr->d_A;
		else if (sum <= sum_n && sum <= sum_p)
		{
			rez->appr->d_A /= 10;
			mezha--;
		}
	}
	rez->appr->d_A = 0.1;
	return (sum);
}

static long double   init_B(t_rez *rez, double mezha)
{
	long double	sum;
	long double	sum_p;
	long double	sum_n;
	int			n;

	n = mezha + 1;
	while (mezha)
	{
		sum = init_A(rez, n - mezha);
		sum_p = search_sum(rez->appr->A, rez->appr->B - rez->appr->d_B, rez->appr->tay, rez->appr->beta, rez);
		sum_n = search_sum(rez->appr->A, rez->appr->B + rez->appr->d_B, rez->appr->tay, rez->appr->beta, rez);
		if (sum > sum_n)
			rez->appr->B += rez->appr->d_B;
		else if (sum > sum_p)
			rez->appr->B -= rez->appr->d_B;
		else if (sum <= sum_n && sum <= sum_p)
		{
			rez->appr->d_B /= 10;
			mezha--;
		}
	}
	rez->appr->d_B = 0.1;
	return (sum);
}

static long double	init_tay(t_rez *rez, double mezha)
{
	long double	sum;
	long double	sum_p;
	long double	sum_n;
	int			n;

	n = mezha + 1;
	while (mezha)
	{
		sum = init_B(rez, n - mezha);
		sum_p = search_sum(rez->appr->A, rez->appr->B, rez->appr->tay - rez->appr->d_tay, rez->appr->beta, rez);
		sum_n = search_sum(rez->appr->A, rez->appr->B, rez->appr->tay + rez->appr->d_tay, rez->appr->beta, rez);
		if (sum > sum_n)
			rez->appr->tay += rez->appr->d_tay;
		else if (sum > sum_p)
			rez->appr->tay -= rez->appr->d_tay;
		else if (sum <= sum_n && sum <= sum_p)
		{
			rez->appr->d_tay /= 10;
			mezha--;
		}
	}
	rez->appr->d_tay = 0.1;
	return (sum);
}

static void 	init_beta(t_rez *rez, int mezha)
{
	long double	sum;
	long double	sum_p;
	long double	sum_n;
	int			n;

	n = mezha + 1;
	while (mezha)
	{
		sum = init_tay(rez, n - mezha);
		sum_p = search_sum(rez->appr->A, rez->appr->B, rez->appr->tay, rez->appr->beta - rez->appr->d_beta, rez);
		sum_n = search_sum(rez->appr->A, rez->appr->B, rez->appr->tay, rez->appr->beta + rez->appr->d_beta, rez);
		if (sum > sum_n)
			rez->appr->beta += rez->appr->d_beta;
		else if (sum > sum_p)
			rez->appr->beta -= rez->appr->d_beta;
		else if (sum <= sum_n && sum <= sum_p)
		{
			if (mezha)
				printf("tochnist %Lf\n", rez->appr->d_beta);
			rez->appr->d_beta /= 10;
			mezha--;
		}
	}
	rez->appr->sum = sum;
}

void			appr_data(t_dyplom *dyplom, int mezha)
{
	int	i;

	i = 0;
	while (i < dyplom->k_rez)
	{
		dyplom->rez[i]->appr->A = 0;
		dyplom->rez[i]->appr->d_A = 0.1;
		dyplom->rez[i]->appr->B = 0;
		dyplom->rez[i]->appr->d_B = 0.1;
		dyplom->rez[i]->appr->tay = 1;
		dyplom->rez[i]->appr->d_tay = 0.1;
		dyplom->rez[i]->appr->beta = 1;
		dyplom->rez[i]->appr->d_beta = 0.1;
		printf("approximate data in T = %d K\n", dyplom->rez[i]->T);
		init_beta(dyplom->rez[i], mezha);
		i++;
	}
}
