NAME		= push_swap
BNS_NAME		= checker

CC			= cc

FLAGS		= -Wall -Wextra -Werror -Iincludes #-fsanitize=address -g

SRC			=	src/main.c \
				src/parsing/parser.c src/parsing/utils_parsing.c src/parsing/utils_stack.c src/parsing/gbcollector.c  \
				src/sorting/instructions/push.c src/sorting/instructions/revrotate.c src/sorting/instructions/rotate.c src/sorting/instructions/swap.c \
				src/sorting/sort/sort_3.c src/sorting/sort/sort_5.c src/sorting/sort/indexing.c  src/sorting/sort/algo.c \

BNS_SRCS	= 	bonus/checker.c \
				bonus/get_next_line.c bonus/get_next_line_utils.c \
				src/parsing/parser.c src/parsing/utils_parsing.c src/parsing/utils_stack.c src/parsing/gbcollector.c  \
				src/sorting/instructions/push.c src/sorting/instructions/revrotate.c src/sorting/instructions/rotate.c src/sorting/instructions/swap.c \


OBJ			= $(SRC:%.c=%.o)

BNS_OBJ			= $(BNS_SRCS:%.c=%.o)

HEADER		= 	includes/push_swap.h \
				includes/checker.h \


all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "🛠️ Creating Objects!!"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "👌 Done"

bonus : $(BNS_NAME)

$(BNS_NAME) : $(BNS_OBJ)
	@$(CC) $(FLAGS) $(BNS_OBJ) -o $(BNS_NAME)
	@echo "✨ Bonus Done"

clean:
	@rm -f $(OBJ) $(BNS_OBJ)
	@echo  "🧨 Deleting OBJS."

fclean: clean
	@rm -f  $(NAME) $(BNS_NAME)
	@echo  "💣 Destroy all"

re: fclean all

.PHONY: clean 