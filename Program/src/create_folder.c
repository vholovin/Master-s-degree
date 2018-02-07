#include "../include/dyplom.h"

void	create_folder(t_dyplom *dyplom)
{
	char	*status;

	printf("create folder\n");
	status = ft_strjoin("mkdir -p ", dyplom->sp);
	if (system(status) != 0)
		error(6);
}
