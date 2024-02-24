/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:52:37 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/23 11:19:43 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (stack && *stack && (*stack)->next)
	{
		(*stack)->number = (*stack)->number + (*stack)->next->number;
		(*stack)->index = (*stack)->index + (*stack)->next->index;
		(*stack)->next->number = (*stack)->number - (*stack)->next->number;
		(*stack)->next->index = (*stack)->index - (*stack)->next->index;
		(*stack)->number = (*stack)->number - (*stack)->next->number;
		(*stack)->index = (*stack)->index - (*stack)->next->index;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
