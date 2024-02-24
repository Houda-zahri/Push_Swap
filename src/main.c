/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:57:01 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 11:28:37 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = parser(ac - 1, av + 1);
		indexing(&stack_a);
		if (is_sorted(stack_a))
			return (0);
		(s_size(0, FLAG_A) < 4) && (sort_3(&stack_a), 0);
		(s_size(0, FLAG_A) > 3 && s_size(0, FLAG_A) < 6) &&
		(sort_5(&stack_a, &stack_b), 0);
		(s_size(0, FLAG_A) > 5) &&
		(level_1(&stack_a, &stack_b), level_2(&stack_a, &stack_b), 0);
	}
	gcollector(0, 0);
	return (0);
}
