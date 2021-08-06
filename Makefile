# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeoffro <lgeoffro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 16:21:12 by lgeoffro          #+#    #+#              #
#    Updated: 2021/07/29 19:01:47 by lgeoffro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Werror -Wextra -I includes/

SOLONG = so_long

LIBFT = libft.a
LIBFT_NAME = ft
LIBFT_DIR = src/libft/

MLX = mlx.a
MLX_NAME = mlx
MLX_DIR = src/mlx/

INCLUDE_DIR = includes

SOLONG_SRC = src/so_long/main.c \
			 src/so_long/map.c \
			 src/so_long/checker.c \
			 src/so_long/get_next_line.c \
			 src/so_long/get_next_line_utils.c \
			 src/so_long/draw.c \
			 src/so_long/exit.c \
			 src/so_long/key_hook.c \
			 src/so_long/player.c \
			 src/so_long/checker2.c \
			 src/so_long/animations.c \

SOLONG_OBJ = $(SOLONG_SRC:.c=.o)

RM = rm -f

all: $(LIBFT) $(SOLONG)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	clang 

$(SOLONG): $(SOLONG_OBJ)
	$(CC) -o $(SOLONG) $(SOLONG_OBJ) -L $(MLX_DIR) -l $(MLX_NAME) -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -l $(LIBFT_NAME) -fsanitize=address

clean:
	$(RM) $(SOLONG_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(SOLONG)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
