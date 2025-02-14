/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:25 by marvin            #+#    #+#             */
/*   Updated: 2025/02/08 23:40:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*bef_last;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = ft_stack_bottom(*stack);
	bef_last = ft_stack_before_bottom(*stack);
	bef_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (str)
		ft_putstr(str);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a, 0);
	rrotate(stack_b, 0);
	ft_putstr("rrr");
}
