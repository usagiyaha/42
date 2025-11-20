# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanren <yanren@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 16:31:05 by yanren            #+#    #+#              #
#    Updated: 2024/11/29 16:31:06 by yanren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# Mandatory part
SRCS		=   ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
				ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
				ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
				ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
				ft_isalpha.c ft_memcpy.c ft_spilt.c ft_strlen.c ft_tolower.c \
				ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
				ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c
OBJS		= $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rules to create the library from mandatory object files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Complie .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	$(RM) $(OBJS)

# Clean up all generated files
fclean: clean
	$(RM) $(NAME)

# Rebuild the project
re: fclean all
