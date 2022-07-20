# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 12:23:43 by mtsuji            #+#    #+#              #
#    Updated: 2022/07/20 17:42:27 by msuji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	philo.c	\
			outils.c	\
			thread.c\
			check_arg.c	\
			outil2.c	\
			action.c	\

OBJS	=	$(SRCS:.c=.o)

HEADER	=	./philo/

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -pthread #-fsanitize=thread

.c.o:
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re


