# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 11:19:33 by david-fe          #+#    #+#              #
#    Updated: 2025/02/12 20:16:22 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

#files

NAME = push_swap.a
OBJ = $(SRC:.c=.o)

SRC = ${SRC_PATH}/main.c ${SRC_PATH}/ft_parse_args.c ${SRC_PATH}/lst_utils.c \
	  ${SRC_PATH}/swaps.c ${SRC_PATH}/pushes.c ${SRC_PATH}/rotates.c \
	  ${SRC_PATH}/rev_rotates.c ${SRC_PATH}/radix_sort.c
SRC_PATH = src

LIBFT = ${LIBFT_PATH}/libft.a
LIBFT_PATH = libft

#rules

all: $(NAME) 

$(NAME): $(OBJ)
	make -C ${LIBFT_PATH} all
	cp ${LIBFT} ${NAME}
	ar rcs $(NAME) $(OBJ)
	cc ${CFLAGS} ${NAME} ${OBJS} -o push_swap

clean:
	make -C ${LIBFT_PATH} clean
	$(RM) $(OBJ) 

fclean: clean
	make -C ${LIBFT_PATH} fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
