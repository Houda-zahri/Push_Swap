/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:42:54 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/20 16:01:53 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
	t_stack *tmp;
	if (stack && *stack)
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->last = tmp->last;
		(*stack)->prev = NULL;
		push_back(stack, tmp);
	}
	
}

void ra(t_stack **stack_a)
{
	if(stack_a && *stack_a)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void rb(t_stack **stack_b)
{
	if(stack_b && *stack_b)
	{	
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	if(stack_a && stack_b && *stack_b && *stack_a)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}