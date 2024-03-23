# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:31:20 by seozkan           #+#    #+#              #
#    Updated: 2023/06/24 18:15:52 by dlariono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_b
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror

YELLOW = \033[33;49;1m
CYAN = \033[33;36;1m
END = \033[0;0m

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_ARG = -framework OpenGl -framework AppKit

SRC = $(shell find src -name '*.c')
INCLUDES = -I includes
# B_SRC = $(wildcard bonus/*.c)

OBJ = ${SRC:.c=.o}
B_OBJ = ${B_SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ)  $(MLX)
			$(CC) $(FLAGS) $(OBJ) $(MLX) $(MLX_ARG) -o $(NAME)
			@echo "$(YELLOW)${NAME} ✔️"
			@echo "$(CYAN)Mandatory files compiled successfully ✔️$(END)"

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


$(MLX):
	@make -s -C $(MLX_DIR)


$(NAME_B): 	$(B_OBJ)  $(MLX)
			$(CC) $(FLAGS) $(B_OBJ) $(MLX) $(MLX_ARG) -o $(NAME_B)
			@echo "$(YELLOW)${NAME_B} ✔️$(END)"

n:
	norminette src  inc

clean:
	${RM} ${OBJ}
	${RM} ${B_OBJ}


fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_B}


mlx:
	make re -C mlx

re: clean mlx all

.PHONY: all clean fclean re mlx
