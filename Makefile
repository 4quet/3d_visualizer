# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:35:59 by lfourque          #+#    #+#              #
#    Updated: 2016/10/17 15:54:22 by lfourque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

SRC = main.c\
	  gpu.c\
	  draw.c\
	  free.c\
	  hooks.c\
	  read_obj.c\
	  shaders.c\
	  set_camera.c\
	  texture.c\
	  load_model.c\
	  get_normals.c\
	  get_colors.c\
	  add_uvs.c\
	  load_bmp.c\
	  get_bounding_box.c\
	  set_uniform.c\
	  get_face_vertices.c

SRC_DIR = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

LIB = -framework OpenGL -framework Appkit 

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(SRC_DIR) inc/scop.h
	@echo "Compiling Scop..."
	@make -C libft/
	@make -C libmath/
	@make -C libmlx/
	@gcc -Wall -Wextra -Werror -I inc/ -I libmath/inc -I libft/includes -I libmlx/ -c $(SRC_DIR)
	@gcc -o $(NAME) -I inc/ libft/libft.a libmath/libmath.a libmlx/libmlx.a $(LIB) $(OBJ)
	@/bin/rm -rf obj/
	@mkdir obj
	@mv $(OBJ) obj/
	@echo "OK"

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf obj/

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
