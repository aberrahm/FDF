# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/09 18:56:32 by aberrahm          #+#    #+#              #
#    Updated: 2017/12/04 01:18:38 by aberrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
FLAGS = -Wall -Wextra -Werror

LFT = ./libft/libft.a
LIBS = $(LFT)

LFT_INC = -I ./libft
INC = $(LFT_INC) -I ./
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SRCS = srcs/create_image.c \
	   srcs/main.c \
	   srcs/pars.c \
	   srcs/event.c \
	   srcs/create_line.c \
	   srcs/create_line1.c \

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME) : $(OBJ)
	make -C ./libft
	@echo "	"
	@echo "\\033[42m- - - - - - - - - - - - - - - - - - - - - - \\033[0m"
	@echo " "
	@echo "\\033[35m\033[1mLib Ok ! Lib Ok ! Lib Ok ! Lib Ok ! Lib Ok !\\033[0m"
	@echo " "
	@echo "\\033[42m- - - - - - - - - - - - - - - - - - - - - - \\033[0m"
	@echo " "
	$(CC) $(FLAGS) $(FRAMEWORK) $(LIBS) $(INC) $(OBJ) -o $(NAME)
	@echo "\\033[43m- - - - - - - - - - - \\033[0m"
	@echo " "
	@echo "\\0033[32m\033[1m  Executable created  \\0033[0m"
	@echo " "
	@echo "\\033[43m- - - - - - - - - - - \\033[0m"
	@echo " "

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	@echo "\\033[42m- - - - - - - - - - - \\033[0m"
	@echo " "
	@echo "\\0033[31m\033[1m  Executable deleted  \\0033[0m"
	@echo " "
	@echo "\\033[42m- - - - - - - - - - - \\033[0m"

re: fclean all

.PHONY : all clean fclean re
