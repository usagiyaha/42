# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanren <yanren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 11:40:26 by yanren            #+#    #+#              #
#    Updated: 2025/07/31 11:40:26 by yanren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I. -Ilib/mlx -Ilib/libft
LDFLAGS = -Llib/libft -lft -Llib/mlx -lmlx -lX11 -lXext -lm 

LIBFT_DIR = ./lib/libft
MLX_DIR = ./lib/mlx

SRCS = event.c helper.c init_game.c map_helper.c map.c so_long.c

OBJS = $(SRCS:.c=.o)

#Targets
all: $(NAME)

$(NAME): $(OBJS) 
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS): %.o:%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

#clean
clean:
	$(RM) $(OBJS)
	@make clean -C lib/libft
	@make clean -C lib/mlx


fclean: clean
	$(RM) $(NAME)
	@make fclean -C lib/libft
	@make clean -C lib/mlx

re: fclean all

.PHONY: all clean fclean re