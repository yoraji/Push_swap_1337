/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:33:01 by marvin            #+#    #+#             */
/*   Updated: 2025/02/08 23:59:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate_both(t_list**a, t_list**b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

static void	rotate_both(t_list**a, t_list**b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

static void	rotate_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate(a, "ra");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrotate(a, "rra");
			(*cost)++;
		}
	}
}

static void	rotate_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate(b, "rb");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrotate(b, "rrb");
			(*cost)++;
		}
	}
}

void	move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	push(b, a, "pa");
}
