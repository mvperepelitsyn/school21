# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 17:48:53 by dfrost-a          #+#    #+#              #
#    Updated: 2018/09/06 21:39:08 by dfrost-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat

SRCS = srcs/main.c srcs/ft_display.c srcs/ft_write.c srcs/ft_strlen.c

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
		@gcc *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
