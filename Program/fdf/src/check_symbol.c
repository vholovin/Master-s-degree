/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:28:25 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:28:33 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_symbol(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == ',' && line[i + 1] == '0' && line[i + 2] == 'x')
			while (line[i] != ' ')
				i++;
		else
		{
			if (line[i] != '-' && (line[i] < '0' || line[i] > '9'))
				error(3);
			i++;
		}
	}
}
