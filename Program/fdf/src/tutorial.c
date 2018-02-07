/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:56:54 by vholovin          #+#    #+#             */
/*   Updated: 2017/04/10 13:57:06 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	tutorial(void)
{
	ft_putstr("\
____________________________\n\
CONTROLS:\n\
turn:\n\
	OX up:         Key: W\n\
	OX down:       Key: S\n\
	OY left:       Key: A\n\
	OY right:      Key: D\n\
	OZ underclock: Key: Q\n\
	OZ onclock:    Key: E\n\
Move:\n\
	Up:             Key: up\n\
	Down:           Key: down\n\
	Left:           Key: left\n\
	Righ:           Key: right\n\
	Center:         Key: ~\n\
Zoom:\n\
	Small zoom +:   Key: +\n\
	Small zoom -:   Key: -\n\
	Big zoom +:     Key: [\n\
	Big zoom -:     Key: ]\n\
\n\
____________________________\n\
");
}
