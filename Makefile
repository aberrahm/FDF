# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/09 18:56:32 by aberrahm          #+#    #+#              #
#    Updated: 2017/12/04 01:19:57 by aberrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

MLX = ./minilibx_macos/libmlx.a
LFT = ./libft/libft.a
LIBS = $(MLX) $(LFT)

MLX_INC = -I ./minilibx_macos
LFT_INC = -I ./libft
INC = $(MLX_INC) $(LFT_INC) -I ./
FRAMEWORK = -framework OpenGL -framework AppKit

SRCS = srcs/create_image.c \
	   srcs/main.c \
	   srcs/pars.c \
	   srcs/event.c \
	   srcs/create_line.c \
	   srcs/create_line1.c \

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	make -C ./libft
	@echo "\\033[35m\033[1m[LIBRARY COMPILED]\\033[0m"
	make -C ./minilibx_macos
	$(CC) $(FRAMEWORK) $(LIBS) $(INC) $(OBJ) -o $(NAME)
	@echo "\\0033[32m\033[1m[EXECUTABLE CREATED]\\0033[0m"

clean:
	make clean -C ./libft
	make clean -C ./minilibx_macos
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	@echo "\\0033[31m\033[1m[EXECUTABLE DELETED]\\0033[0m"

re: fclean all

.PHONY : all clean fclean re
