SRC= main.c gnl/get_next_line_utils.c gnl/get_next_line.c src/*.c

CC = gcc

FLGS = -Wall -Werror -Wextra

VALGFLGS = --vgdb=full \
		 --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt

FBSIZE = -D BUFFER_SIZE=42

HEADER = ft_grep.h

NAME = s21_grep

ARGS = ""

all :$(NAME)
	
$(NAME): $(SRC) $(HEADER)
	@echo "compiling ..."
	@$(CC) $(FLGS) $(FBSIZE) $(SRC) -o $(NAME)

run: $(NAME)
	@./$(NAME) $(ARGS)

clean:
	@echo "cleaning all objects"
	@rm -f $(NAME)

fclean: clean
	@rm -f valgrind-out.txt

re: fclean all

debug: $(SRC) $(HEADER)
	@echo "compiling with -g ..."
	@$(CC) $(FLGS) -g $(FBSIZE) $(SRC) -o $(NAME)

style: $(SRC)
	clang-format -n $(SRC)

valgrind: $(NAME)
	@valgrind $(VALGFLGS) ./$(NAME) $(ARGS)

.PHONY: all clean fclean re


#&.c : &.o libft.a 
