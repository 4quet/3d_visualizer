# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 18:26:36 by lfourque          #+#    #+#              #
#    Updated: 2016/10/17 15:29:58 by lfourque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmath.a

SRC = mtx_new.c mtx_set.c mtx_get.c mtx_zero.c mtx_identity.c mtx_lookat.c\
	  mtx_perspective.c mtx_copy.c mtx_free.c mtx_mult.c mtx_sub.c\
	  mtx_scale.c mtx_translate.c mtx_rotate.c mtx_transf.c\
	  quat_to_matrix.c triangle_face_normal.c\
	  vector_length.c vector_normalize.c\
	  vector_cross.c vector_dot.c vector_get.c vector_new3.c

SRC_DIR = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(SRC_DIR) inc/libmath.h
	@echo "Compiling libmath..."
	@gcc -Wall -Wextra -Werror -c $(SRC_DIR) -I inc/ -I ../libft/includes
	@ar rc $(NAME) $(OBJ)
	@rm -rf obj/
	@mkdir obj/
	@mv $(OBJ) obj/
	@ranlib $(NAME)
	@echo "OK"

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf obj/

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
