/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:02:17 by exam              #+#    #+#             */
/*   Updated: 2017/02/03 17:14:15 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dyplom.h"

static int		ft_n_len(long int value, int base)
{
	int			len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		value = -value;
		if (base == 10)
			len++;
	}
	while (value)
	{
		value = value / base;
		len++;
	}
	return (len);
}

static char		*ft_solve(char *str, long int nb, int base, int len)
{
	int			res;
	int			i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (base == 10)
		{
			str[i] = '-';
			i++;
		}
	}
	while (len > i)
	{
		len--;
		res = nb % base;
		if (res < 10)
			str[len] = '0' + res;
		else
			str[len] = 'A' + res - 10;
		nb = nb / base;
	}
	return (str);
}

char			*ft_itoa_base(int value, int base)
{
	char		*str;
	int			len;
	long int	nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	len = ft_n_len(nb, base);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	str = ft_solve(str, nb, base, len);
	return (str);
}
