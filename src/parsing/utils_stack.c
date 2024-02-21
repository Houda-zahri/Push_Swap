/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:09:11 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/20 15:53:08 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create(int num)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return(NULL);
	node->number = num;
	node->next = NULL;
	node->index = 0;
	node->last = NULL;
	return (node);
}

void add_back(t_stack **stack, t_stack *new)
{
	t_stack *head;

	if (!stack || !new)
		return ;
	if(!*stack)
		return ((*stack) = new, (*stack)->last = new, s_size(2, FLAG_A), (void)0);
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
	new->prev = head;
	(*stack)->last = new;
	s_size(2, FLAG_A);
}

void push_back(t_stack **stack, t_stack *new)
{
	if(!stack || !new)
		return ;
	if(!*stack)
		return ((*stack) = new, (*stack)->last = new, (void)0);
	(*stack)->last->next = new;
	new->prev = (*stack)->last;
	new->next = NULL;
	new->last = NULL;
	(*stack)->last = new;
}

void push_front(t_stack **stack, t_stack *new)
{
	if(!stack || !new)
		return ;
	new->last = new;
	new->next = NULL;
	new->prev = NULL;
	if(*stack)
	{
		(*stack)->prev = new;
		new->next = *stack;
		new->last = (*stack)->last;
		new->prev = NULL;
	}
	*stack = new;
}

int s_size(char mode, t_flags flag)
{
	static int a;
	static int b;
 
	if(mode == 1)
	{
		a += (flag == FLAG_A) * 1 + (flag == FLAG_B) * -1;
		b += (flag == FLAG_B) * 1 + (flag == FLAG_A) * -1;
		return (0);
	}
	else if(mode == 2)
	{
		a++;
		return (0);
	}
	
	return ((flag == FLAG_A) * a + (flag == FLAG_B) * b);
}