#include "../include/dyplom.h"

long int		ft_power_d(long int nb, int pow)
{
	int x;

	x = nb;
	while (pow > 1)
	{
		nb *= x;
		pow--;
	}
	return (nb);
}

int		ft_strisdigit(char *str)
{
	int		i;
	int		end;

	i = -1;
	end = 0;
	while (str[++i] == ' ')
		;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57) && end == 0)
			i++;
		else if (str[i] == ' ' && end == 0)
			end = 1;
		else
			return (0);
	}
	return (1);
}

static int		ft_strlen_nb(char *str)
{
	int		i;

	i = -1;
	while (ft_isdigit(str[++i]))
		;
	return (i);
}

long int	ft_atoi_d(char *str)
{
	int minus;
	long int n;

	minus = 0;
	n = 0;
	while (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = '1';
		str++;
	}
	while ((*str <= '9') && (*str >= '0'))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	if (minus == '1')
		n = -n;
	return (n);
}

long double			ft_atoid(char *str, char symb)
{
	long double	result;
	int			i;
	char		*a;

	i = -1;
	a = NULL;
	result = 0;
	while (str[++i] != symb)
	{
		if (str[i] == '\0')
			return (ft_atoi_d(str));
	}
	a = &str[i + 1];
	i = -1;
	if (!ft_strisdigit(&a[++i]))
		ft_atoi_d(str);
	result = ft_atoi_d(str);
	if (result < 0)
		result -= (double)ft_atoi_d(a) / (double)ft_power_d(10, ft_strlen_nb(a));
	else
		result += (double)ft_atoi_d(a) / (double)ft_power_d(10, ft_strlen_nb(a));
	if (str[0] == '-' && ft_atoi_d(str) == 0)
		result *= -1;
	return (result);
}
