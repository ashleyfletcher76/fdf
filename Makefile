# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 13:25:34 by asfletch          #+#    #+#              #
#    Updated: 2024/01/02 10:02:25 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME		= fdf

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

MLX42_URL	= https://github.com/codam-coding-college/MLX42.git
MLX42_DIR	= MLX42
MLX42_LIB	= $(MLX42_DIR)/build/libmlx42.a

SRCS		= src/main.c src/print_debug.c \
 			src/map/background.c src/map/draw_grid.c src/map/map.c \
			src/map/rotation.c \
			src/init/init.c \
			src/hooks/hooks.c \
			src/free_and_error/free_and_error.c \
			src/pixels/pixel.c \

INCLUDES	= -I$(MLX42_DIR)/include -I header -I libft
LDINCLUDES	= -L$(MLX42_DIR)/build -lmlx42 -L$(LIBFT_DIR) -lft -lglfw -framework Cocoa -framework OpenGL -framework IOKit
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INCLUDES)
OBJS		= $(SRCS:.c=.o)
RM			= rm -f

all: $(NAME)

$(LIBFT_LIB):
			make -C $(LIBFT_DIR)
			make -C $(LIBFT_DIR) bonus

$(MLX42_DIR) :
			git clone $(MLX42_URL) $(MLX42_DIR)

$(MLX42_LIB): $(MLX42_DIR)
			cd $(MLX42_DIR) && cmake -B build && cmake --build build


$(NAME): $(LIBFT_LIB) $(MLX42_LIB) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDINCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		make -C $(LIBFT_DIR) clean
		rm -rf $(MLX42_DIR) clean

fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean
		rm -rf $(MLX42_DIR)

re:		fclean all

.PHONY: all clean fclean re
