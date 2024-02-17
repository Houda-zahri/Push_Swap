#include "push_swap.h"

void push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	tmp = *src;
	*src = (*src)->next;
	push_front(dest,tmp);
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
	if(!stack_b)
		return ;
	push(&stack_b, &stack_a);
	size(1, FLAG_A);
	write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	if(!stack_a)
		return ;
	size(1, FLAG_B);
	push(&stack_a, &stack_b);
	write(1, "pb\n", 3);
}