# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sojung <sojung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 14:30:40 by sojung            #+#    #+#              #
#    Updated: 2022/05/31 11:27:09 by sojung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c init.c check_arg.c util.c time.c routine.c finish.c forks.c \
actions.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

CC = clang

FLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
