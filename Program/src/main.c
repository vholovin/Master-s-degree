#include "../include/dyplom.h"

int		main(int argc, char **argv)
{
	t_dyplom *dyplom;

	dyplom = init_dyplom(argc);
	read_file(dyplom, argv);
	create_folder(dyplom);
	create_fdf(dyplom, "data_raw_fdf.fdf", 0, 1);
	create_fdf(dyplom, "data_int_fdf.fdf", 1, 1);
	set_data(dyplom);
	create_file(dyplom);
	appr_data(dyplom, 4);
	create_appr(dyplom);
	check_appr(dyplom);
	create_fdf(dyplom, "appr_fdf.fdf", 0, 0);
	free(dyplom);
	return (0);
}

//  #include <locale.h>
//  setlocale(LC_ALL,"Russian");
//  printf("Введите имя файла: \n”);
