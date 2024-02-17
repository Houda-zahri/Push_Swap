NAME		= push_swap

CC			= cc

FLAGS		= -Wall -Wextra -Werror -Iincludes/  #-fsanitize=address -g

SRC			=	src/main.c \
				src/parsing/parser.c src/parsing/utils_parsing.c src/parsing/utils_stack.c  \
				

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