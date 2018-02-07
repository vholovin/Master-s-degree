/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:50:32 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:51:02 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int status)
{
	if (status == 0)
		ft_putendl("Use fdf file");
	else if (status == 1)
		ft_putendl("Map errror");
	else if (status == 2)
		ft_putendl("Malloc error");
	else if (status == 3)
		ft_putendl("Symbol error");
	exit(0);
}
