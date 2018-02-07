#include "../include/dyplom.h"

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
