/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:52:37 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/20 16:06:15 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap (t_stack **stack, t_flags flag)
{
	if (stack && *stack && s_size(0,flag) > 1)
	{
		(*stack)->number = 	(*stack)->number + (*stack)->next->number;
		(*stack)->index = 	(*stack)->index + (*stack)->next->index;
		(*stack)->next->number = (*stack)->number - (*stack)->next->number;
		(*stack)->next->index = (*stack)->index - (*stack)->next->index;
		(*stack)->number = 	(*stack)->number - (*stack)->next->number;
		(*stack)->index = 	(*stack)->index- (*stack)->next->index;
	}
}
void sa(t_stack **stack)
{
	if(stack && *stack)
	{
		swap(stack,FLAG_A);
		write(1, "sa\n", 3);
	}
}
void sb(t_stack **stack)
{
	if(stack && *stack)
	{
		swap(stack,FLAG_B);
		write(1, "sb\n", 3);
	}
}
void ss(t_stack **stack_a, t_stack **stack_b)
{
	if(stack_a && stack_b && *stack_b && *stack_a)
	{
		swap(stack_a,FLAG_A);
		swap(stack_b,FLAG_B);
		write(1, "ss\n", 3);
	}
}
