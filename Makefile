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
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

#files

NAME = push_swap.a
OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))
OBJ_PATH = .obj

SRC = ${SRC_PATH}/main.c ${SRC_PATH}/ft_parse_args.c ${SRC_PATH}/lst_utils.c \
	  ${SRC_PATH}/swaps.c ${SRC_PATH}/pushes.c ${SRC_PATH}/rotates.c \
	  ${SRC_PATH}/rev_rotates.c ${SRC_PATH}/radix_sort.c ${SRC_PATH}/sort_utils.c
SRC_PATH = src

LIBFT = ${LIBFT_PATH}/libft.a
LIBFT_PATH = libft

#rules

all: $(OBJ_PATH) $(NAME) 

$(NAME): $(OBJ)
	make -C ${LIBFT_PATH} all
	cp ${LIBFT} ${NAME}
	ar rcs $(NAME) $(OBJ)
	cc ${CFLAGS} ${NAME} ${OBJS} -o push_swap

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CC_FLAGS) -I/usr/include -c $< -o $@

clean:
	make -C ${LIBFT_PATH} clean
	$(RM) $(OBJ) $(OBJ_PATH) 

fclean: clean
	make -C ${LIBFT_PATH} fclean
	$(RM) $(NAME)

re: fclean all

n:
#	norminette push_swap.h ${SRC_PATH} ${LIBFT_PATH}
	@norminette ${LIBFT_PATH} 
	@echo -e '\n'
	@norminette ${SRC_PATH}
	@echo -e '\n'
	@norminette push_swap.h

.PHONY: all clean fclean re
