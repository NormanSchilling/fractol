# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 11:20:37 by nschilli          #+#    #+#              #
#    Updated: 2015/02/27 14:42:12 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

SRCDIR = srcs/

CFILES =	main.c \
			init.c \
			hook.c \
			display.c \
			mandelbrot.c \
			julia.c \


MLX = -L/usr/X11/lib -lmlx -lXext -lX11

SRC = $(addprefix $(SRCDIR), $(CFILES))

GCC = gcc 

OBJ = $(SRC:.c=.o)

HDDIR = includes/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) libft/libft.a $(MLX)
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

%.o: %.c
	@echo -n .
	@$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re: fclean all

.PHONY: clean fclean re