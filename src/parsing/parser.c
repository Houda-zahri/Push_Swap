#include "push_swap.h"

t_stack *parser(int ac, char **av) // ac -1, av +1
{
	int i = -1;
	t_stack *stack = NULL;
	char *tok;

	while (++i < ac)
	{
		tok = ft_strtok(av[i]);
		if (!tok)
			ft_error();
		while (tok)
		{
			add_back(&stack, create(ft_atoi(tok)));
			tok = ft_strtok(NULL);
		}
	}
	return(stack);
}