# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/01 13:21:50 by daviwel           #+#    #+#              #
#    Updated: 2016/07/01 13:26:10 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

INCLUDES = -I/nfs/zfs-student-6/users/daviwel/.brew/include/SDL2 -D_THREAD_SAFE

LIBS = -L/nfs/zfs-student-6/users/daviwel/.brew/lib -lSDL2

all: $(NAME)

$(NAME):
	clang -Wall -Werror -Wextra $(INCLUDES) main.c $(LIBS)

install:
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrew_fix/master/install.sh)" 
	export PATH=$HOME/.brew/bin:$PATH
	brew install htop
	brew install SDL2
