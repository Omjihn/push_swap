# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbricot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 16:29:58 by gbricot           #+#    #+#              #
#    Updated: 2023/05/16 16:39:31 by gbricot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

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
		src/ft_is_sort.c \
		src/ft_free_all.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_memcpy.c \
		libft/ft_split.c

SRC_CHECKER =	src/checker/main_checker.c \
		src/checker/ft_read_inputs.c \
		src/checker/ft_exec.c \
		src/ft_check.c \
		src/ft_is_sort.c \
		src/operation_1.c \
		src/operation_2.c \
		src/operation_3.c \
		src/ft_init.c \
		src/ft_free_all.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_memcpy.c \
		libft/ft_split.c

OBJ_PS = $(SRC_PS:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

LIB = 	printf/libftprintf.a

$(NAME): $(OBJ_PS)
	@cd printf && make
	$(CC) $(CFLAGS) $(OBJ_PS) $(LIB) -o $(NAME)

bonus: $(OBJ_CHECKER)
	@cd printf && make
	$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIB) -o $(NAME_B)

all: $(NAME) bonus

clean:
	@cd printf && make clean
	@rm -f $(OBJ_PS) $(OBJ_CHECKER)

fclean: clean
	@cd printf && make fclean
	@rm -f $(NAME) $(NAME_B)

re: fclean all
