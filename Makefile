# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 12:23:43 by mtsuji            #+#    #+#              #
#    Updated: 2022/06/14 13:13:14 by mtsuji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS	=	./srcs/philo.c	\
			./srcs/outils.c	\
			./srcs/thread.c\
			./srcs/check_arg.c	\
#			./srcs/-----.c	\
#			./srcs/-----.c	\
#			./srcs/-----.c	\

OBJS	=	$(SRCS:.c=.o)

HEADER	=	./includes/

CC	=	gcc

RM	=	rm -f

#CFLAGS	=	-Wall -Wextra -Werror -pthread -g3 -fsanitize=thread
CFLAGS	=	-Wall -Wextra -Werror -g3
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


