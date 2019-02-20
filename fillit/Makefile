NAME = fillit

SRCS = src/main.c

OBJECT = main.o

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft/includes 

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc $(FLAGS) -I $(INCLUDES) -o $(OBJECT) -c $(SRCS)
	@gcc -o $(NAME) $(OBJECT) -I $(INCLUDES) -L libft/ -lft

clean:
	@/bin/rm -f $(OBJECT)
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	
re: fclean all

