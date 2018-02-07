# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vholovin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:49:22 by vholovin          #+#    #+#              #
#    Updated: 2017/01/06 15:59:15 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
NAME_dSYM	= $(NAME:=.dSYM)

CC			= gcc
FLAG		= -Wall -Wextra -Werror
FRAMEWORK	= -lmlx -framework OpenGL -framework AppKit
LOCAL		= -I minilibX -g -L minilibX

LIBFT		= libft/libft.a

SRC     = src/main.c				\
			src/tutorial.c			\
			src/check_file.c		\
			src/init_fdf.c			\
			src/read_file.c			\
			src/ft_atoi_base.c		\
			src/check_symbol.c		\
			src/error_file.c		\
			src/adaptive_size.c		\
			src/adaptive_rotate.c	\
			src/adaptive_center.c	\
			src/draw.c				\
			src/draw_lines.c		\
			src/draw_color.c		\
			src/key_hook.c			\
			src/move_size.c
OBJ     = $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@
	printf '\033[31m ✔  %s\n\033[0m' "$<"

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAG) $(LIBFT) $(LOCAL) $(FRAMEWORK) $(OBJ) -o $(NAME)
	printf '\033[32m ✔  %s\n\033[0m' "Create FDF"

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	rm -rf $(NAME_dSYM)
	printf '\033[33m ✔  %s\n\033[0m' "Clean FDF"

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
	printf '\033[33m ✔  %s\n\033[0m' "Fclean FDF"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
