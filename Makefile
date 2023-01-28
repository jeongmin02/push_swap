# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 15:08:28 by jerhee            #+#    #+#              #
#    Updated: 2023/01/28 15:09:17 by jerhee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall
NAME	=	push_swap
SRCS	=	main.c utils.c ft_split.c swap.c \
			push.c rotate.c reverse_rotate.c \
			fill_stack.c sand_watch.c hard_sort.c \
			free.c
OBJS	=	main.o utils.o ft_split.o swap.o \
			push.o rotate.o reverse_rotate.o \
			fill_stack.o sand_watch.o hard_sort.o \
			free.o

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re : fclean all