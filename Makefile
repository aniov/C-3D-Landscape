# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvoina <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 10:05:52 by mvoina            #+#    #+#              #
#    Updated: 2015/12/10 23:08:59 by mvoina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf_source/fdf.c\
      fdf_source/read_and_create_matrix.c\
      get_next_line/get_next_line.c\
      get_next_line/ft_itoa.c\
      fdf_source/create_window.c\
      fdf_source/read_input.c\
      fdf_source/ini_env.c\
      fdf_source/draw_line.c\
      fdf_source/rotate.c\
      fdf_source/helper_matrix.c\
      fdf_source/colors.c\

OBJ = fdf.o\
      read_and_create_matrix.o\
      get_next_line.o\
      ft_itoa.o\
      create_window.o\
      read_input.o\
      ini_env.o\
      draw_line.o\
      rotate.o\
      helper_matrix.o\
      colors.o\

FLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -c $(SRC) $(FLAGS)
	@gcc $(OBJ) $(MLX) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
