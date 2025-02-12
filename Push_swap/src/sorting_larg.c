/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_larg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:44 by marvin            #+#    #+#             */
/*   Updated: 2025/02/08 23:56:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	highest_index(t_list *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_tree(t_list **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = highest_index(*stack);
	if ((*stack)->index == highest)
		rotate(stack, "ra");
	else if ((*stack)->next->index == highest)
		rrotate(stack, "rra");
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, "sa");
}

void	push_three(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			rotate(stack_a, "ra");
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push(stack_a, stack_b, "pb");
		pushed++;
	}
}

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_stack_size(*stack_a);
	lowest_pos = lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rrotate(stack_a, "rra");
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate(stack_a, "ra");
			lowest_pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_three(stack_a, stack_b);
	sort_tree(stack_a);
	while (*stack_b)
	{
		target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
