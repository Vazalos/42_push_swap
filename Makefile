# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 11:19:33 by david-fe          #+#    #+#              #
#    Updated: 2024/12/23 18:21:47 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#files

NAME = push_swap.a
OBJ = $(SRC:.c=.o)

SRC = main.c ft_parse_args.c lst_utils.c swaps.c pushes.c rotates.c

LIBFT = ${LIBFT_PATH}/libft.a
LIBFT_PATH = libft

#rules

all: $(NAME) 

$(NAME): $(OBJ)
	make -C ${LIBFT_PATH} all
	cp ${LIBFT} ${NAME}
	ar rcs $(NAME) $(OBJ)
	cc ${CFLAGS} ${NAME} ${OBJS}

clean:
	make -C ${LIBFT_PATH} clean
	$(RM) $(OBJ) 

fclean: clean
	make -C ${LIBFT_PATH} fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
