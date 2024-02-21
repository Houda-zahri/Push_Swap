NAME		= push_swap

CC			= cc

FLAGS		= -Wall -Wextra -Werror -Iincludes -fsanitize=address -g

SRC			=	src/main.c \
				src/parsing/parser.c src/parsing/utils_parsing.c src/parsing/utils_stack.c  \
				src/sorting/instructions/push.c src/sorting/instructions/revrotate.c src/sorting/instructions/rotate.c src/sorting/instructions/swap.c \
				src/sorting/sort/sort_3.c src/sorting/sort/sort_5.c src/sorting/sort/indexing.c  src/sorting/sort/algo.c \
				

OBJ			= $(SRC:%.c=%.o)

HEADER		= includes/push_swap.h

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "🛠️ Creating Objects!!"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "👌 Done"


clean:
	@rm -f $(OBJ)
	@echo  "🧨 Deleting OBJS."

fclean: clean
	@rm -f  $(NAME)
	@echo  "💣 Destroy all"

re: fclean all

.PHONY: clean 