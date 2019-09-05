#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bellyn-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 14:29:30 by bellyn-t          #+#    #+#              #
#    Updated: 2019/04/29 12:46:55 by bellyn-t         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fillit

SRC = srcs/validation.c \
	srcs/fillit.c \
	srcs/board.c \
	srcs/board_2.c \
	srcs/kate.c \
	srcs/listfunc.c \
	srcs/libfunc.c \
	srcs/tetr.c \
	srcs/moving.c \
	srcs/main.c

OBJ  = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

.PHONY: all
all: ${NAME}

%.o:%.c
	@echo "Make object files from $(SRC)"
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@echo "Сompilation $(NAME)"
	@echo "Wait a second ..."
	@gcc -o $(NAME) $(OBJ)
	@echo "bellyn-t && gbeqqo are the best ♥"

clean:
	@echo "Clean object files"
	@rm -rf $(OBJ)

fclean: clean
	@echo "Clean $(NAME)"
	@rm -rf $(NAME)

re: fclean all