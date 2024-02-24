/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:19:25 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/23 21:53:29 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	level_1(t_stack **stack_a, t_stack **stack_b)
{
	int	lp;
	int	pivot1;
	int	pivot2;

	(1) && (lp = -2, 1) && (pivot1 = 0, 1) &&
	(pivot2 = s_size(0, FLAG_A) / 6, 0);
	if (!stack_a || !*stack_a)
		return ;
	while (s_size(0, FLAG_A) != 3)
	{
		pivot1 += s_size(0, FLAG_A) / 3;
		while (s_size(0, FLAG_B) < pivot1)
		{
			((*stack_a)->index < pivot1) && (pb(stack_a, stack_b), 0);
			((*stack_b) && (*stack_b)->next
				&& (*stack_b)->index > lp && (*stack_b)->index < pivot2
				&& (*stack_a)->index >= pivot1 && (rr(stack_a, stack_b), 1)) ||
			(((*stack_b) && (*stack_b)->next && (*stack_b)->index > lp &&
			(*stack_b)->index < pivot2) && (rb(stack_b), 1)) ||
			(((*stack_a)->index >= pivot1) && (ra(stack_a), 0));
		}
		(1) && (lp = pivot1, 1) && (pivot2 = s_size(0, FLAG_A) / 6 + lp, 0);
	}
	(s_size(0, FLAG_A) == 3) && (sort_3(stack_a), 0);
}

bool	search_prev(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*head;

	i = 1;
	head = *stack_b;
	while (i <= s_size(0, FLAG_B))
	{
		if ((*stack_a)->index - 1 == head->index && i <= s_size(0, FLAG_B) / 2)
			return (0);
		else if ((*stack_a)->index - 1 == head->index
			&& i > s_size(0, FLAG_B) / 2)
			return (1);
		head = head->next;
		i++;
	}
	return (0);
}

void	util(t_stack **stack_a, t_stack **stack_b, int *check)
{
	pa(stack_a, stack_b);
	ra(stack_a);
	*check = 1;
}

void	level_2(t_stack **stack_a, t_stack **stack_b)
{
	int	f_s;
	int	check;

	f_s = s_size(0, FLAG_A) + s_size(0, FLAG_B);
	check = 0;
	while (*stack_b)
	{
		while ((*stack_a)->index - 1 != (*stack_b)->index)
		{
			if (!search_prev(stack_a, stack_b))
			{
				(!check || (*stack_a)->last->index < (*stack_b)->index) &&
				(util(stack_a, stack_b, &check), 1) || (rb(stack_b), 0);
			}
			else
			{
				(!check || (*stack_a)->last->index < (*stack_b)->index) &&
				(util(stack_a, stack_b, &check), 1) || (rrb(stack_b), 0);
			}
		}
		pa(stack_a, stack_b);
		while ((*stack_a)->index - 1 == (*stack_a)->last->index)
			rra(stack_a);
		(f_s == (*stack_a)->last->index + 1) && (check = 0, 0);
	}
}
