/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:06:22 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 12:46:57 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <libc.h>

typedef enum s_falgs
{
	FLAG_A,
	FLAG_B,
}	t_flags;

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*last;
	int				index;
}	t_stack;

typedef struct s_gc
{
	void			*content;
	struct s_gc		*next;
}	t_gc;

char	*ft_strtok(char *str);
int		ft_atoi(char *str);
void	ft_error(void);
bool	is_sorted(t_stack *stack);
t_stack	*create(int num);
void	add_back(t_stack **stack, t_stack *new);
void	push_back(t_stack **stack, t_stack *new);
t_stack	*parser(int ac, char **av);
void	push_front(t_stack **stack, t_stack *new);
int		s_size(char mode, t_flags flag);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	indexing(t_stack **stack);
void	level_1(t_stack **stack_a, t_stack **stack_b);
bool	search_prev(t_stack **stack_a, t_stack **stack_b);
void	level_2(t_stack **stack_a, t_stack **stack_b);
void	*gcollector(size_t size, int mode);

#endif 