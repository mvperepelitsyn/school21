# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfrost-a <dfrost-a@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 15:30:25 by dfrost-a          #+#    #+#              #
#    Updated: 2019/06/04 19:51:08 by dfrost-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = parser.c format_checker.c ft_printf.c extract_number.c extract_unicode.c\
extract_string.c extract_float.c apply_format.c format.c apply_utils.c

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc -I $(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECT) ./libft/*.o
	@ranlib $(NAME)
	
clean:
	@/bin/rm -f $(OBJECT)
	@make -C libft/ clean
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	
re: fclean all
