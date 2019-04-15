# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfrost-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 15:30:25 by dfrost-a          #+#    #+#              #
#    Updated: 2019/04/13 17:32:07 by dfrost-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c solve.c check_tetr.c create_tetr.c map.c read_tetr.c\
	   iamuseful.c exit.c

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = libft/includes

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	@gcc $(FLAGS) -o $(NAME) $(OBJECT) -I $(INCLUDES) -L libft/ -lft
	
clean:
	@/bin/rm -f $(OBJECT)
	@make -C libft/ clean
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	
re: fclean all
