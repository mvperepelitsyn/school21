# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 15:34:10 by dfrost-a          #+#    #+#              #
#    Updated: 2018/09/06 18:19:57 by dfrost-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS = srcs/main.c	srcs/ft_display.c 

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
