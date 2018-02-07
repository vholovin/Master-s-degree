/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:27:24 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 12:27:59 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		open_file(char *fdf_file)
{
	int		fd;

	fd = open(fdf_file, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(fdf_file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

int				check_file(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
		error(0);
	else
	{
		fd = open_file(argv[1]);
		if (fd == 0)
			error(1);
	}
	return (fd);
}
