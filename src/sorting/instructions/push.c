/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:17:39 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 13:25:57 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	if (tmp->next)
	{
		*src = tmp->next;
		(*src)->last = tmp->last;
		(*src)->prev = NULL;
	}
	else
		*src = NULL;
	push_front(dest, tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	s_size(1, FLAG_A);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	s_size(1, FLAG_B);
	write(1, "pb\n", 3);
}
