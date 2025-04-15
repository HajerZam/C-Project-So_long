# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 15:09:40 by halzamma          #+#    #+#              #
#    Updated: 2025/04/15 15:09:40 by halzamma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------------------------------------------------
# Configration
# -----------------------------------------------------------------------------

NAME			= so_long

# -----------------------------------------------------------------------------
# Directories to include and to compile
# -----------------------------------------------------------------------------

SRC_DIR			= src
INC_DIR			= include
LIB_DIR			= lib
MLX_DIR			= $(LIB_DIR)/minilibx-linux
LIBFT_DIR		= $(LIB_DIR)/libft
PRINTF_DIR		= $(LIB_DIR)/ft_printf

# -----------------------------------------------------------------------------
# Files to compile
# -----------------------------------------------------------------------------

SRCS			= $(wildcard $(SRC_DIR)/*.c) main.c
OBJS			= $(SRCS:.c=.o)

# -----------------------------------------------------------------------------
# Compiler Flags
# -----------------------------------------------------------------------------

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBS			= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# -----------------------------------------------------------------------------
# Rules 
# -----------------------------------------------------------------------------

all: $(NAME)

$(NAME): libft printf mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# -----------------------------------------------------------------------------
# Libs
# -----------------------------------------------------------------------------

libft:
	$(MAKE) -C $(LIBFT_DIR)

printf:
	$(MAKE) -C $(PRINTF_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

# -----------------------------------------------------------------------------
# Clean / Rebuild
# -----------------------------------------------------------------------------

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) BONUS=1 all

.PHONY: all clean fclean re libft printf mlx bonus