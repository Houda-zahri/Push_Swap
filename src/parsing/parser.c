/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:25:34 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/23 22:47:31 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parser(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	char	*tok;

	stack = NULL;
	i = -1;
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
	return (stack);
}
