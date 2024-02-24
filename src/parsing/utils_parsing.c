/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:11:32 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 11:20:06 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strtok(char *str)
{
	static char	*hold;
	char		*token;

	if (str)
		hold = str;
	if (!hold || !*hold)
		return (NULL);
	while (*hold && (*hold == ' ' || *hold == '\t'))
		hold++;
	if (!*hold)
		return (NULL);
	token = hold;
	while (*hold && *hold != 32 && *hold != '\t')
		hold++;
	if (*hold)
		*hold++ = 0;
	return (token);
}

void	ft_error(void)
{
	gcollector(0, 0);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (!str || !*str)
		ft_error();
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!*str)
		ft_error();
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			ft_error();
	}
	if (*str)
		ft_error();
	return (res * sign);
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}
