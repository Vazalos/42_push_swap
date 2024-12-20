# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:52:00 by david-fe          #+#    #+#              #
#    Updated: 2024/11/19 14:57:44 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

#files
NAME = libftprintf.a

OBJ = $(SRC:.c=.o)
SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putunbr.c ft_putstr.c ft_puthex.c ft_putptr.c

LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

#rules
all: $(NAME) 

$(NAME): $(OBJ)
	make -C ${LIBFT_PATH} all
	cp ${LIBFT} ${NAME}
	ar rcs $(NAME) $(OBJ)

clean:
	make -C ${LIBFT_PATH} clean
	$(RM) $(OBJ) 

fclean: clean
	make -C ${LIBFT_PATH} fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
