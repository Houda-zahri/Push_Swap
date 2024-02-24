/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:05:33 by hzahri            #+#    #+#             */
/*   Updated: 2024/02/24 11:22:00 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool	find_nl(const char *s);
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
void	indexing(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	revrotate(t_stack **stack);
void	*gcollector(size_t size, int mode);

#endif