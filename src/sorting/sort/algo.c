/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:19:25 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/21 09:16:18 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void level_1(t_stack **stack_a,t_stack **stack_b)
{
	int lp;
	int pivot1;
	int pivot2;
	
	lp = -2;
	pivot1 = 0;
	pivot2 = s_size(0,FLAG_A)/6;
	
	if (!stack_a || !*stack_a)
		return;
	while (s_size(0,FLAG_A) != 3 )
	{
		pivot1 += s_size(0,FLAG_A)/3;
		
		while (s_size(0,FLAG_B) < pivot1)
		{
			if ((*stack_b) && (*stack_b)->next && (*stack_b)->index > lp && (*stack_b)->index < pivot2 && (*stack_a)->index >= pivot1)
				rr(stack_a,stack_b);
			else if ((*stack_b) && (*stack_b)->next && (*stack_b)->index > lp && (*stack_b)->index < pivot2)
				rb(stack_b);
			else if ((*stack_a)->index >= pivot1)
				ra(stack_a);
			if ((*stack_a)->index < pivot1)
				pb(stack_a, stack_b);
		}
		lp = pivot1;
		pivot2 = s_size(0,FLAG_A)/6+lp;
	}
	if (s_size(0,FLAG_A) == 3)
		sort_3(stack_a);
}
bool search_prev(t_stack **stack_a,t_stack **stack_b)
{
	int i;
	t_stack *head;
	
	i = 1;
	head = *stack_b;
	while (i <= s_size(0,FLAG_B))
	{
		if ((*stack_a)->index-1 == head->index && i <= s_size(0,FLAG_B)/2)
			return(0);
		else if ((*stack_a)->index-1 == head->index && i > s_size(0,FLAG_B)/2)
			return(1);
		head = head->next;
		i++;
	}
	return(0);
}
void level_2(t_stack **stack_a,t_stack **stack_b)
{
	
	while (*stack_b)
	{
		if(!search_prev(stack_a,stack_b))
		{
			if ((*stack_a)->index-1 == (*stack_b)->index)
			{
				pa(stack_a,stack_b);
				while ((*stack_a)->index-1 == (*stack_a)->last->index)
					rra(stack_a);
			}
			else if (((*stack_a)->last->index+1 == s_size(0,FLAG_A) || (*stack_a)->last->index < (*stack_b)->index) && (*stack_a)->index-1 == (*stack_b)->next->index && (*stack_a)->index > (*stack_b)->next->index)
			{
				pa(stack_a,stack_b);
				rr(stack_a,stack_b);
			}
			else if ((*stack_a)->last->index+1 == s_size(0,FLAG_A) || (*stack_a)->last->index < (*stack_b)->index)
			{
				pa(stack_a,stack_b);
				ra(stack_a);
			}
			else
				rb(stack_b);
		}
		if(search_prev(stack_a,stack_b))
		{
			(s_size(0,FLAG_B) > 1) && (rrb(stack_b),0);
			if ((*stack_a)->index-1 == (*stack_b)->index)
			{
				pa(stack_a,stack_b);
				while ((*stack_a)->index-1 == (*stack_a)->last->index)
					rra(stack_a);
			}
			else if ((*stack_a)->last->index+1 == s_size(0,FLAG_A) || (*stack_a)->last->index < (*stack_b)->index)
			{
				pa(stack_a,stack_b);
				ra(stack_a);
			}
			else
				rrb(stack_b);
		}
	}
}
