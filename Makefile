# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 10:11:08 by jmoyano-          #+#    #+#              #
#    Updated: 2022/08/22 18:06:40 by jmoyano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRCS = push_swap.c \
		checkers.c \
		error.c \
		filler.c \
		list_act.c \
		mount_board.c \
		ordering_actions.c \
		orders.c \
		orders2.c \
		searchers.c \
		sort_selector.c \
		sorters.c \
		num_sort.c \
		radix_sort_utils.c \
		sorting_algo.c \
		smart_selector_big.c \
		
OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	make -C ./Moyano_library
	${CC} ${CFLAGS} $(OBJS) -I ./Moyano_library -L ./Moyano_library -l ft -o ${NAME}

all: $(NAME)

clean:
	make clean -C ./Moyano_library
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./Moyano_library
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re