#include "../include/dyplom.h"

void	error(int status)
{
	if (status == 0)
		ft_putendl("Use txt file");
	else if (status == 1)
		ft_putendl("txt errror");
	else if (status == 2)
		ft_putendl("Malloc error");
	else if (status == 3)
		ft_putendl("Symbol error");
	else if (status == 4)
		ft_putendl("create txt error");
	else if (status == 5)
		ft_putendl("close create txt error");
	else if (status == 6)
		ft_putendl("create folder error");
	exit(0);
}
