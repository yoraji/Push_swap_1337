/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:16 by marvin            #+#    #+#             */
/*   Updated: 2025/02/08 23:40:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **src, t_list **dest, char *str)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	ft_putstr(str);
}

void	swap(t_list **stack, char *str)
{
	int	tmp;

	if (ft_stack_size(*stack) > 1)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
		tmp = (*stack)->index;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->index = tmp;
	}
	if (str)
		ft_putstr(str);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr("ss");
}

void	rotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_stack_bottom(*stack);
	tmp->next = NULL;
	last->next = tmp;
	if (str)
		ft_putstr(str);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_putstr("rr");
}
