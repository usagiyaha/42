# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanren <yanren@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 17:06:30 by yanren            #+#    #+#              #
#    Updated: 2025/03/16 14:01:33 by yanren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = ft_printf.c \
		put_bytype.c put_char.c put_string.c \
		put_hex.c put_number.c put_pointer.c 
		
OBJS = $(SRCS:.c=.o)

#Rules

all: $(NAME)

makelibft:
			@make -C $(LIBFTDIR)
			@cp $(LIBFTDIR)/$(LIBFTNAME) .


$(NAME): makelibft $(OBJS)
		@cp $(LIBFTNAME) $(NAME)
		@ar -r $(NAME) $(OBJS)

clean:
		@rm -f $(OBJS)
		@cd $(LIBFTDIR) && make clean

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFTNAME)
		@cd $(LIBFTDIR) && make fclean

re: fclean all