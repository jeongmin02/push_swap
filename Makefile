CC = gcc
CFLAGS = -Werror -Wextra -Wall
SRCS_M = main.c utils.c ft_split.c swap.c push.c rotate.c reverse_rotate.c \
		fill_stack.c sand_watch.c
OBJS_M = main.o utils.o ft_split.o swap.o push.o rotate.o reverse_rotate.o \
		fill_stack.o sand_watch.o
AR = ar rcs
NAME = push_swap.a

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean :
	rm -f $(OBJS_M) $(OBJS_B)

fclean : clean
	rm -f bonus
	rm -f $(NAME)

$(NAME) : $(OBJS_M)
	ar rc $(NAME) $(OBJS_M)

re : fclean all