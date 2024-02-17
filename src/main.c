#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	// t_stack *stack_b;

	stack_a = parser(ac - 1, av + 1);
	while(stack_a)
	{
		printf("|  num -> %d   |\n", stack_a->number);
		stack_a = stack_a->next;
	}
	printf(">> size = %zu\n", size(0, FLAG_A) );

}	