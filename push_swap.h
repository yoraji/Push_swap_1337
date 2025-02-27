/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:19:56 by ael-bako          #+#    #+#             */
/*   Updated: 2025/02/12 03:34:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

int			is_sorted(t_list *stack);
void		sort_tree(t_list **stack);
void		push_three(t_list **stack_a, t_list **stack_b);
void		sort(t_list **stack_a, t_list **stack_b);
void		cost(t_list **stack_a, t_list **stack_b);
void		cheapest_move(t_list **stack_a, t_list **stack_b);
int			lowest_index_position(t_list **stack);
void		target_position(t_list **a, t_list **b);
void		move(t_list **a, t_list **b, int cost_a, int cost_b);
t_list		*fill_stack_content(int ac, char **av);
void		assign_index(t_list *stack_a, int stack_size);
t_list		*ft_stack_bottom(t_list *stack);
t_list		*ft_stack_before_bottom(t_list *stack);
t_list		*stack_new(int content);
int			ft_stack_size(t_list	*stack);
void		ft_stack_add_back(t_list **stack, t_list *new);
void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
char		**ft_split(char *str, char sep, int *size);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
int			str_ncmp(char *str1, char *str2, int n);
void		free_stack_1(t_list **stack);
void		free_stack(t_list **stack_a, t_list **stack_b);
void		exit_error(t_list **stack_a, t_list **stack_b);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);
char		**fill_tab(char **av, int *size, int ac);
void		swap(t_list **stack, char *str);
void		ss(t_list **stack_a, t_list **stack_b);
void		push(t_list **src, t_list **dest, char *str);
void		rotate(t_list **stack, char *str);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrotate(t_list **stack, char *str);
void		rrr(t_list **stack_a, t_list **stack_b);
int			cheack_input(char **av);
int			is_empty(char *av);
int			is_digit(char c);
int			is_sign(char c);
void		print_stack(t_list	*stack_a);
int			compare_num(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
int			is_space(char c);
void		free_split(char **split);
void		exit_error__(void);
void		free_tab(char **tab);
long		ft_atol(const char *str);
#endif