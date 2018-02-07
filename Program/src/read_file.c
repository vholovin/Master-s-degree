#include "../include/dyplom.h"

static char		*ft_space(char *space)
{
	int i;

	i = ft_strlen(space);
	while (space[i] != '/')
	{
		space[i] = '\0';
		i--;
	}
	space = ft_strjoin(space, "Rezult/");
	return (space);
}

static int		open_file(char *rez_file)
{
	int fd;

	fd = open(rez_file, O_DIRECTORY);
	if (fd >= 0)
		error(1);
	fd = open(rez_file, O_RDONLY);
	if (fd < 0)
		error(1);
	return (fd);
}

static t_rez	*create_elem(t_rez *buf, int fd)
{
	int		i;
	char	*line;
	char	**str_xy;

	i = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		str_xy = ft_strsplit(line, '\t');
		buf->t[i] = ft_atoid(str_xy[0], ',');
		buf->u[i] = ft_atoid(str_xy[1], ',');
		i++;
	}
	return (buf);
}

static int		set_temp(char *name)
{
	int	i;
	int	p;
	int	T;

	i = 0;
	p = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '/')
			p = i + 1;
		i++;
	}
	T = ft_atoi(name + p);
	return(T);
}

void			read_file(t_dyplom *dyplom, char **argv)
{
	int		i;
	int		fd;

	fd = 0;
	i = 1;
	while (i <= dyplom->k_rez)
	{
		fd = open_file(argv[i]);
		dyplom->rez[i - 1] = init_rez(argv[i]);
		dyplom->rez[i - 1] = create_elem(dyplom->rez[i - 1], fd);
		dyplom->rez[i - 1]->T = set_temp(argv[i]);
		printf("read T = %d K\n", dyplom->rez[i - 1]->T);
		i++;
	}
	dyplom->sp = ft_space(argv[1]);
}
