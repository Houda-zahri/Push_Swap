# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <libc.h>


#define A 0
#define B 1

typedef enum s_falgs
{
	FLAG_A,
	FLAG_B
} t_flags;

typedef struct s_stack
{
	int number;
	struct s_stack *next;
	struct s_stack *last;
}t_stack;

char *ft_strtok(char * str);
int ft_atoi(char *str);
void ft_error();
t_stack *create(int num);
void add_back(t_stack **stack, t_stack *new);
void push_back(t_stack **stack, t_stack *new);
t_stack *parser(int ac, char **av);
void push_front(t_stack **stack, t_stack *new);
size_t size(char mode, t_flags flag);

#endif