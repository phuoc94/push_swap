# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 18:26:02 by phuocngu          #+#    #+#              #
#    Updated: 2024/12/17 17:39:42 by phuocngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
OP_DIR = ./operations
HT_DIR = ./hash_table
LIS_DIR = ./lis

SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/stack.c \
            $(SRC_DIR)/utils.c \
            $(SRC_DIR)/push_swap.c \
            $(SRC_DIR)/print_error.c \
            $(SRC_DIR)/parse_input.c \
            $(SRC_DIR)/check_duplicates.c \
            $(SRC_DIR)/sorting_helpper.c \
            $(OP_DIR)/operations_helpper.c \
            $(OP_DIR)/push_operations.c \
            $(OP_DIR)/reverse_rotate_operations.c \
            $(OP_DIR)/rotate_operations.c \
            $(OP_DIR)/swap_operations.c \
            $(HT_DIR)/hash_table.c \
            $(LIS_DIR)/lis_helpper.c \
            $(LIS_DIR)/lis.c

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
