NAME = gnl

SRCS = get_next_line.c main.c

OBJECT = get_next_line.o main.o

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft/includes

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I $(INCLUDES) -o get_next_line.o -c get_next_line.c
	@gcc $(FLAGS) -I $(INCLUDES) -o main.o -c main.c
	@gcc -o $(NAME) $(OBJECT) -I $(INCLUDES) -L libft/ -lft

clean:
	@/bin/rm -f $(OBJECT)
	
fclean: clean
	@/bin/rm -f $(NAME)
	
re: fclean all

