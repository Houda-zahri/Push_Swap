/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:59:29 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/20 16:19:07 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_stack(t_stack *stack)
{
	int max;
	
	if (!stack)
		return(0);
	max = (stack)->number;
	while (stack)
	{
		if (max < (stack)->number)
			max = (stack)->number;
		stack = (stack)->next;
	}
	return (max);
}
void sort_3(t_stack **stack_a)
{
	int max;

	if (!stack_a || !*stack_a)
		return;
	if(s_size(0, FLAG_A) == 3)
	{
		max = max_stack(*stack_a);
		((max == (*stack_a)->number) && (ra(stack_a), 0));
		((max == (*stack_a)->next->number) && (rra(stack_a), 0));
	}
	if ((*stack_a)->next->number < (*stack_a)->number)
		sa(stack_a);
}
