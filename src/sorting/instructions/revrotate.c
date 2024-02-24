/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:11:01 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 13:28:58 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack **stack)
{
	t_stack	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->last;
		tmp->prev->next = NULL;
		(*stack)->last = tmp->prev;
		push_front(stack, tmp);
	}
}

void	rra(t_stack **stack_a)
{
	revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	revrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	write(1, "rrr\n", 4);
}
