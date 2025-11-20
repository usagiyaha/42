NAME = push_swap
CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I. -Ilibft
LDFLAGS = -Llibft -lft

LIBFT_DIR = ./libft

SRCS = build_stack.c indexing.c push_swap.c push.c reverse_rotate.c rotate.c sort_utils.c \
		sort.c stack_utils.c swap.c utils.c

OBJS = $(SRCS:.c=.o)

#Targets
all: $(NAME)

$(NAME): $(OBJS) 
	@make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS): %.o:%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

#clean
clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)


fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re