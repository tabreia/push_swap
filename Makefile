# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabreia- <tabreia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 16:45:44 by tabreia-          #+#    #+#              #
#    Updated: 2023/03/30 16:55:23 by tabreia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

DEPS = libft/libft.a

NAME = push_swap

SRC = check_order.c frees.c handle_stacks.c main.c operations.c \
push_swap.c validation.c big_stack.c finds.c push_swap_utils.c checks.c \
validation_utils.c big_stack_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)  -o $(NAME)

clean:
	$(MAKE) $@ -C ./libft
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libft