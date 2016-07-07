# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/07/05 15:33:17 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

PATH = src/

SRC = $(PATH)main.c \
	  $(PATH)vector_dot.c \
	  $(PATH)vector_new.c \
	  $(PATH)vector_sub.c \
	  $(PATH)vector_add.c \
	  $(PATH)vector_cross.c \
	  $(PATH)vector_scale.c \
	  $(PATH)mlx_image_put_pixel.c \
	  $(PATH)key_hook.c \
	  $(PATH)close_window.c \
	  $(PATH)intersect_ray_trace.c \
	  $(PATH)sphere_raytrace.c \
	  $(PATH)get_input.c \
	  $(PATH)fill_spheres.c\
	  $(PATH)intersect_triangle.c\

OBJ = $(SRC:.c=.o)

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	clang -Wall -Werror -Wextra -c $(SRC)
	/bin/mv *.o src
	clang -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
