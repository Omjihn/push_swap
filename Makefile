# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:29:58 by gbricot           #+#    #+#              #
#    Updated: 2023/05/12 16:20:53 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_PS =	src/main.c \
		src/push_swap.c \
		src/operation_1.c \
		src/operation_2.c \
		src/operation_3.c \
		src/ft_check.c \
		src/ft_add_index.c \
		src/ft_split_stack.c \
		src/ft_sort_stacks.c \
		src/ft_init.c \
		src/ft_free_all.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_memcpy.c \
		libft/ft_split.c

SRC_CHECKER =	

OBJ_PS = $(SRC:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

LIB = 	printf/libftprintf.a

$(NAME): $(OBJ_PS)
	@cd printf && make
	$(CC) $(CFLAGS) $(OBJ_PS) $(LIB) -o $(NAME)

bonus: $(OBJ_CHECKER)

all: $(NAME) $(bonus)

clean:
	@cd printf && make clean
	@rm -f $(OBJ_PS) $(OBJ_CHECKER)

fclean: clean
	@cd printf && make fclean
	@rm -f $(NAME)

re: fclean all
