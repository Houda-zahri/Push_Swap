#include "push_swap.h"

char *ft_strtok(char *str)
{
	static char *hold = NULL;
	char *token;

	if (str)
		hold = str;
	if (!hold || !*hold)
		return(NULL);
	while (*hold && (*hold == ' ' || *hold == '\t'))
		hold++;
	if (!*hold)
		return(NULL);
	token = hold;
	while (*hold && *hold != 32 && *hold != '\t')
		hold++;
	if(*hold)
		*hold++ = 0;
	return(token);
}

void ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

int ft_atoi(char *str)
{
	int sign = 1;
	long res = 0;

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
	return (res*sign);
}
 bool is_sorted(t_stack **stack)
 {
	t_stack *head;

	if (!stack || !*stack)
		return(0);
	head = *stack;
	while (head->next && head->index < head->next->index)
		head = head->next;
	if (!head->next || head->index == s_size(0,FLAG_A)+1)
		return(1);
	return(0);
 }
