# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoulaim <msoulaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 23:07:17 by msoulaim          #+#    #+#              #
#    Updated: 2020/12/02 19:57:58 by msoulaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = color.c complex.c color_c.c draw.c ctrl.c fractal1.c fractal.c ft_fractol.c mouse.c main.c fractal2.c key.c

OBJ = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) fractol.h complex.h
	make -C libft/
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRCS)
	norminette fractol.h complex.h