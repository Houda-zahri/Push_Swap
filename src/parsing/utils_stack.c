/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:09:11 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/17 06:12:46 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create(int num)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	node->number = num;
	node->next = NULL;
	return (node);
}

void add_back(t_stack **stack, t_stack *new)
{
	t_stack *head;

	if (!stack || !new)
		return ;
	if(!*stack)
		return ((*stack) = new, (*stack)->last = new, size(1, FLAG_A), (void)0);
	head = *stack;
	while (head->next)
	{
		if(head->number == new->number)
			ft_error();
		head = head->next;
	}
	if(head->number == new->number)
		ft_error();
	head->next = new;
	(*stack)->last = new;
	size(1, FLAG_A);
}

void push_back(t_stack **stack, t_stack *new)
{
	if(!stack || !new)
		return ;
	if(!*stack)
		return ((*stack) = new, (*stack)->last = new, (void)0);
	(*stack)->last->next = new;
	(*stack)->last = new;
}

void push_front(t_stack **stack, t_stack *new)
{
	if(!stack || !new)
		return ;
	new->last = new;
	new->next = NULL;
	if(*stack)
	{
		new->next = *stack;
		new->last = (*stack)->last;
	}
	*stack = new;
}

size_t size(char mode, t_flags flag)
{
	static size_t a;
	static size_t b;
 
	if(mode)
	{
		a += (flag == FLAG_A) * 1 + (flag == FLAG_B) * -1;
		b += (flag == FLAG_B) * 1 + (flag == FLAG_A) * -1;
		return (0);
	}
	return ((flag == FLAG_A) * a + (flag == FLAG_B) * b);
}