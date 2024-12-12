# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 18:26:02 by phuocngu          #+#    #+#              #
#    Updated: 2024/12/12 16:51:14 by phuocngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c \
			operations_helpper.c \
			push_operations.c \
			reverse_rotate_operations.c \
			rotate_operations.c \
			stack.c \
			swap_operations.c \
			utils.c

OBJS = $(SRC_FILES:.c=.o)

NAME = push_swap

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT_NAME)

FT_PRINTF_DIR = ft_printf
FT_PRINTF_NAME = libftprintf.a
FT_PRINTF_PATH = $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_DIR) $(FT_PRINTF_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH) $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH) $(FT_PRINTF_PATH)

$(LIBFT_PATH):
	make -C $(LIBFT_DIR)

$(FT_PRINTF_PATH):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
