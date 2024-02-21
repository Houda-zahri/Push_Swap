#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	if(ac > 1)
	{
		stack_b = NULL;
		stack_a = parser(ac - 1, av + 1);
		indexing(&stack_a);

		if(is_sorted(&stack_a))
			return(0);


		(s_size(0, FLAG_A) < 4) && (sort_3(&stack_a),0);
		(s_size(0, FLAG_A) > 3 && s_size(0, FLAG_A) < 6) && (sort_5(&stack_a, &stack_b),0);
		(s_size(0, FLAG_A) > 5) && (level_1(&stack_a, &stack_b),level_2(&stack_a, &stack_b),0);

		while(stack_a)
		{
			printf("|  num -> %d | indx -> %d  \n", stack_a->number, stack_a->index);
			stack_a = stack_a->next;
		}
		printf("------------------\n");
		while(stack_b)
		{
			printf("|  num -> %d   | indx -> %d  |\n", stack_b->number, stack_b->index);
			stack_b = stack_b->next;
		}
	}
	return(0);
}	