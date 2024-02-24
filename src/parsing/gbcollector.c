/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbcollector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:33:11 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 11:13:43 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_gc(t_gc **gc)
{
	t_gc	*tmp;
	t_gc	*node;

	tmp = *gc;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		free(node->content);
		free(node);
	}
	gc = NULL;
}

void	*gcollector(size_t size, int mode)
{
	static t_gc	*gc;
	t_gc		*node;
	void		*data;

	if (mode)
	{
		data = malloc(size);
		if (!data)
			return (clear_gc(&gc), NULL);
		node = malloc(sizeof(t_gc));
		if (!node)
			return (clear_gc(&gc), free(data), NULL);
		node->content = data;
		node->next = gc;
		gc = node;
		return (data);
	}
	else
		return (clear_gc(&gc), NULL);
}
