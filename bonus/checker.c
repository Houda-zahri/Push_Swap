/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:57:45 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 11:29:00 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && ((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	checking(t_stack **stack_a, t_stack **stack_b)
{
	char	*instr;

	instr = get_next_line(0);
	while (instr)
	{
		((!ft_strcmp(instr, "pa\n")) && (push(stack_b, stack_a), 1)) ||
			((!ft_strcmp(instr, "pb\n")) && (push(stack_a, stack_b), 1)) ||
			((!ft_strcmp(instr, "sa\n")) && (swap(stack_a), 1)) ||
			((!ft_strcmp(instr, "sb\n")) && (swap(stack_b), 1)) ||
			((!ft_strcmp(instr, "ss\n")) &&
			(swap(stack_a), swap(stack_b), 1)) ||
			((!ft_strcmp(instr, "ra\n")) && (rotate(stack_a), 1)) ||
			((!ft_strcmp(instr, "rb\n")) && (rotate(stack_b), 1)) ||
			((!ft_strcmp(instr, "rr\n")) &&
			(rotate(stack_a), rotate(stack_b), 1)) ||
			((!ft_strcmp(instr, "rra\n")) && (revrotate(stack_a), 1)) ||
			((!ft_strcmp(instr, "rrb\n")) && (revrotate(stack_b), 1)) ||
			((!ft_strcmp(instr, "rrr\n")) &&
			(revrotate(stack_a), revrotate(stack_b), 1)) ||
			(ft_error(), 0);
		free(instr);
		instr = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = parser(ac - 1, av + 1);
		checking(&stack_a, &stack_b);
		if (is_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	gcollector(0, 0);
	return (0);
}
