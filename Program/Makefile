NAME		= dyplom
NAME_dSYM	= $(NAME:=.dSYM)

CC			= gcc
FLAG		= -Wall -Wextra -Werror -O2 -pipe

LIBFT		= libft/libft.a

SRC     = src/main.c			\
		src/init_file.c			\
		src/read_file.c			\
		src/error_file.c		\
		src/check_symbol.c		\
		src/ft_atoid.c			\
		src/ft_itoa_base.c		\
		src/set_data.c			\
		src/appr_data.c			\
		src/create_folder.c		\
		src/create_file.c		\
		src/create_appr.c		\
		src/create_fdf.c	
OBJ     = $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@
	printf '\033[31m ✔  %s\n\033[0m' "$<"

$(NAME): $(OBJ)
	make -C libft/
	make -C fdf/
	$(CC) $(FLAG) $(LIBFT) $(OBJ) -o $(NAME)
	printf '\033[32m ✔  %s\n\033[0m' "Create Dyplom"

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	rm -rf $(NAME_dSYM)
	printf '\033[33m ✔  %s\n\033[0m' "Clean Dyplom"

fclean: clean
	make -C libft/ fclean
	make -C fdf/ fclean
	rm -f $(NAME)
	printf '\033[33m ✔  %s\n\033[0m' "fclean Dyplom"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
