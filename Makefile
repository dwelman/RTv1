# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/07/04 10:58:39 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

PATH = src/

SRC = $(PATH)main.c \
	  $(PATH)vector_dot.c \
	  $(PATH)vector_new.c \
	  $(PATH)vector_sub.c

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
