/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:22:19 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/20 16:19:33 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void indexing(t_stack **stack)
{
	t_stack *head;
	t_stack *tmp;
	
	if (!stack || !*stack)
		return;
	tmp = *stack;
	while (tmp)
	{
		head = tmp->next;
		while (head)
		{
			if (tmp->number > head->number)
				tmp->index++;
			else
				head->index++;
			head = head->next;
		}
		tmp = tmp->next;
	}
	
}