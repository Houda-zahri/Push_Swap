/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:25:34 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/20 14:25:48 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *parser(int ac, char **av)
{
	int i = -1;
	t_stack *stack = NULL;
	char *tok;

	while (++i < ac)
	{
		tok = ft_strtok(av[i]);
		if (!tok)
			ft_error();
		while (tok)
		{
			add_back(&stack, create(ft_atoi(tok)));
			tok = ft_strtok(NULL);
		}
	}
	return(stack);
}