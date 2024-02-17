/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:52:37 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/17 05:59:46 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap (t_stack *stack, t_flags flag)
{
	if(!stack || size(0, flag) < 2)
		return;
	stack->number = stack->number + stack->next->number;
	stack->next->number = stack->number - stack->next->number;
	stack->number = stack->number - stack->next->number;
}

void sa(t_stack *stack)
{
	swap(stack,FLAG_A);
	write(1, "sa\n", 3);
}
void sb(t_stack *stack)
{
	swap(stack,FLAG_B);
	write(1, "sb\n", 3);
}
void ss(t_stack *stack)
{
	swap(stack,FLAG_A);
	swap(stack,FLAG_B);
	write(1, "ss\n", 3);
}