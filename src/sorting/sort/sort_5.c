/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:25:02 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 14:15:04 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	(!(*stack_a)->next->index) && (sa(stack_a), 0);
	while ((*stack_a)->index)
		rra(stack_a);
	(!(*stack_a)->index) && (pb(stack_a, stack_b), 0);
	if (s_size(0, FLAG_A) > 3)
	{
		((*stack_a)->next->index) && (sa(stack_a), 0);
		while ((*stack_a)->index != 1)
			rra(stack_a);
		((*stack_a)->index) && (pb(stack_a, stack_b), 0);
	}
	(s_size(0, FLAG_A) == 3) && (sort_3(stack_a), 0);
	while (*stack_b)
		pa(stack_a, stack_b);
}
