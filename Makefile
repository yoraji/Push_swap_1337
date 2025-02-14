NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ./src/check_input.c ./src/main.c ./src/move_function.c ./src/operations2.c ./src/utils1.c \
	./src/operations1.c ./src/pos.c ./src/sorting_larg.c ./src/ft_stack.c  \
	./src/string_utils.c ./src/utils2.c ./src/utils.c ./src/printf_stack.c ./src/utils3.c \

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)
fclean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re
